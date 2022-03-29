
#include "philo.h"

void *test()
{
    printf("HELLO \n");
    return NULL;
}
int main(int ac, char *av[])
{
   t_philo philo;
   pthread_t *thread_id;
    int i;

   init_philo(&philo);
    if (ac == 5 || ac == 6)
    {
         set_philo(&philo, ac, av);
        thread_id =(pthread_t *)malloc(sizeof(pthread_t) * philo.number_of_philosophers);
        if (!thread_id)
            return 1;
        i = 0;
        while (i < philo.number_of_philosophers)
        {
            if (pthread_create(thread_id + i, NULL, test, NULL) != 0)
                return 2;
            i++;
        }
        i = 0;
         while (i < philo.number_of_philosophers)
        {
            if (pthread_join(thread_id[i], NULL) != 0)
                return 2;
            i++;
        }
    
    }
    return 0;
}