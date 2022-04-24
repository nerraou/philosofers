#include "philo.h"

void	*monitor_each_must_eat(void *argv)
{
	t_params	*param;

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

void	*monitor(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;

	philo = argv;
	while (!philo->params->finish)
	{
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->params->finish_mutex);
		gettimeofday(&now, NULL);
		ms = time_to_ms(now) - time_to_ms(philo->last_time_to_eat);
		gettimeofday(&now, NULL);
		if (ms >= philo->params->time_to_die && philo->params->finish == 0)
		{
			printf("%lld\t%d\t %s\n", time_to_ms(now) - time_to_ms(philo->params->create_at), philo->id + 1, "died");
			philo->params->finish = 1;
		}
		pthread_mutex_unlock(&philo->params->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
	}
	return (NULL);
}
