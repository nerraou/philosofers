#include "philo.h"

void create_philos(t_params *params)
{
    int i;
    pthread_t thread;

    gettimeofday(&params->create_at, NULL);
    i = 0;
    while (i < params->num_of_philosophers)
    {
        params->philos[i].last_time_to_eat = params->create_at;
        pthread_create(&params->philos[i].thread, NULL, philo, &params->philos[i]);

        pthread_create(&thread, NULL, monitor, &params->philos[i]);
        pthread_detach(thread);
        ++i;
    }
    if (params->nt_must_eat != 0)
    {
        pthread_create(&thread, NULL, monitor_each_must_eat, params);
        pthread_detach(thread);
    }
}