
#include "philo.h"

pthread_mutex_t mutex;
void *philo_thread(void *philosopher)
{
    t_params *param;

    param = (t_params *)philosopher;
    pthread_mutex_lock(&mutex);
    printf("HELLO philo number %d\n", param->philo_id);
    param->philo_id++;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int ac, char *av[])
{
    t_params param;
    pthread_t *thread_id;
    int i;

    init_params(&param);
    if (ac == 5 || ac == 6)
    {
        set_params(&param, ac, av);
        pthread_mutex_init(&mutex, NULL);
        thread_id = (pthread_t *)malloc(sizeof(pthread_t) * param.number_of_philosophers);
        if (!thread_id)
            return 1;
        i = 0;
        while (i < param.number_of_philosophers)
        {
            if (pthread_create(thread_id + i, NULL, philo_thread, (void *)&param) != 0)
                return 2;
            i++;
        }
        i = 0;
        while (i < param.number_of_philosophers)
        {
            if (pthread_join(thread_id[i], NULL) != 0)
                return 2;
            i++;
        }
        pthread_mutex_destroy(&mutex);
    }
    return 0;
}