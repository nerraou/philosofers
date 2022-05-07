#include "philo.h"

void *monitor_each_must_eat(void *argv)
{
	t_params *param;

	param = argv;
	while (!param->finish)
	{
		pthread_mutex_lock(&param->finish_mutex);
		if (param->num_of_eat_finish_philo == param->num_of_philosophers)
			param->finish = 1;
		pthread_mutex_unlock(&param->finish_mutex);
	}
	return (NULL);
}

void *monitor(void *argv)
{
	t_philo *philo;
	struct timeval now;
	long long ms;

	philo = argv;
	while (1)
	{
		pthread_mutex_lock(&philo->params->finish_mutex);
		if (!philo->params->finish)
		{
			pthread_mutex_lock(&philo->check_mutex);
			gettimeofday(&now, NULL);
			ms = time_to_ms(now) - time_to_ms(philo->last_time_to_eat);
			if (ms >= philo->params->time_to_die && philo->params->finish == 0)
			{
				print_state(philo, "died", 0);
				philo->params->finish = 1;
			}
			pthread_mutex_unlock(&philo->check_mutex);
		}
		else
		{
			pthread_mutex_unlock(&philo->params->finish_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->params->finish_mutex);
	}
	return (NULL);
}
