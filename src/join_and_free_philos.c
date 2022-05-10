#include "philo.h"

void join_and_free_philos(t_params *param)
{
	int i;

	i = 0;
	while (i < param->num_of_philosophers)
	{
		pthread_join(param->philos[i].thread, NULL);
		pthread_mutex_destroy(&param->philos[i].check_mutex);
		i++;
	}
	pthread_mutex_destroy(&param->finish_mutex);
	pthread_mutex_destroy(&param->pickup_fork);
	free(param->philos);
	free(param->forks);
}
