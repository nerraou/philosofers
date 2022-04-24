#include "philo.h"

static void pickup_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print_state(philo, "has taken a fork");
    pthread_mutex_lock(philo->left_fork);
    print_state(philo, "has taken a fork");
    
}
static void	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	usleep(philo->params->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
}

static void eating(t_philo *philo)
{
    long long ms;

    pthread_mutex_lock(&philo->check_mutex);
    gettimeofday(&philo->last_time_to_eat, NULL);
    ms = time_to_ms(philo->last_time_to_eat) - time_to_ms(philo->params->create_at);
    pthread_mutex_lock(&philo->params->finish_mutex);
    	if (!philo->params->finish)
		printf("%lld\t%d\t %s\n", ms, philo->id + 1, "is eating");
	philo->num_of_eat += 1;
	if (philo->num_of_eat == philo->params->nt_must_eat)
		philo->params->num_of_eat_finish_philo += 1;
	pthread_mutex_unlock(&philo->params->finish_mutex);
	usleep(philo->params->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->check_mutex);
}

void *philo(void *argv)
{
    t_philo *philo;

    philo = argv;
    if (philo->id % 2 == 0)
		usleep(philo->params->time_to_eat * 1000);
	while (!philo->params->finish)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}