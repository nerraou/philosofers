#include "philo.h"

static void pickup_fork(t_philo *philo)
{
	t_fork *left;
	t_fork *right;

	pthread_mutex_lock(&philo->params->pickup_fork);
	right = &philo->params->forks[philo->right_fork];
	left = NULL;
	if (philo->params->num_of_philosophers > 1)
		left = &philo->params->forks[philo->left_fork];
	if (!right->is_taken)
	{
		philo->params->forks[philo->right_fork].is_taken = 1;
		philo->has_forks = 1;
		print_state(philo, "has taken a fork", 1);
	}
	if (philo->params->num_of_philosophers > 1 && !left->is_taken)
	{
		philo->params->forks[philo->left_fork].is_taken = 1;
		philo->has_forks = 2;
		print_state(philo, "has taken a fork", 1);
	}
	pthread_mutex_unlock(&philo->params->pickup_fork);
}

static void sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping", 1);
	usleep(philo->params->time_to_sleep * 1000);
}

static void thinking(t_philo *philo)
{
	print_state(philo, "is thinking", 1);
}

static void eating(t_philo *philo)
{
	long long ms;

	pthread_mutex_lock(&philo->params->pickup_fork);
	if (philo->has_forks == 2)
	{
		pthread_mutex_unlock(&philo->params->pickup_fork);
		pthread_mutex_lock(&philo->check_mutex);
		gettimeofday(&philo->last_time_to_eat, NULL);
		ms = time_to_ms(philo->last_time_to_eat);
		pthread_mutex_lock(&philo->params->finish_mutex);
		print_state(philo, "is eating", 0);
		philo->num_of_eat += 1;
		if (philo->num_of_eat == philo->params->nt_must_eat)
			philo->params->num_of_eat_finish_philo += 1;
		pthread_mutex_unlock(&philo->params->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
		usleep(philo->params->time_to_eat * 1000);
		pthread_mutex_lock(&philo->params->pickup_fork);
		philo->params->forks[philo->left_fork].is_taken = 0;
		philo->params->forks[philo->right_fork].is_taken = 0;
		philo->has_forks = 0;
		pthread_mutex_unlock(&philo->params->pickup_fork);
	}
	else
		pthread_mutex_unlock(&philo->params->pickup_fork);
}

void *philo(void *argv)
{
	t_philo *philo;

	philo = argv;
	while (!philo->params->finish)
	{

		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
