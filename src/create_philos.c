#include "philo.h"

void create_philos(t_params *params)
{
    int i;
    pthread_t thread;
    struct timeval create_at;

    gettimeofday(&params->create_at, NULL);
    i = 0;
    while (i < params->num_of_philosophers)
    {
        params->philos[i].last_time_to_eat = params->create_at;
        pthread_create(&params->philos[i].thread, NULL, philo, &params->philos[i]);
        i += 2;
    }
    usleep(100);
    gettimeofday(&create_at, NULL);
    i = 1;
    while (i < params->num_of_philosophers)
    {
        params->philos[i].last_time_to_eat = create_at;
        pthread_create(&params->philos[i].thread, NULL, philo, &params->philos[i]);
        i += 2;
    }
    pthread_create(&thread, NULL, monitor, params);
    pthread_detach(thread);
}
