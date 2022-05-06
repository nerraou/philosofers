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
		print_state(philo, "has taken a fork");
	}
	if (philo->params->num_of_philosophers > 1 && !left->is_taken)
	{
		philo->params->forks[philo->left_fork].is_taken = 1;
		philo->has_forks = 2;
		print_state(philo, "has taken a fork");
	}
	// printf("\n%d has_forks: %d\n", philo->id, philo->has_forks);
	pthread_mutex_unlock(&philo->params->pickup_fork);
}

static void sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	usleep(philo->params->time_to_sleep * 1000);
}

static void thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
}

static void eating(t_philo *philo)
{
	long long ms;

	//the forks are taken but not from the same philo
	pthread_mutex_lock(&philo->check_mutex);
	if (philo->has_forks == 2)
	{
		pthread_mutex_unlock(&philo->check_mutex);
		printf("test%d\n", philo->has_forks);
		gettimeofday(&philo->last_time_to_eat, NULL);
		ms = time_to_ms(philo->last_time_to_eat);
		pthread_mutex_lock(&philo->params->finish_mutex);
		if (!philo->params->finish)
			printf("%lld\t%d\t %s\n", ms, philo->id + 1, "is eating");
		philo->num_of_eat += 1;
		if (philo->num_of_eat == philo->params->nt_must_eat)
			philo->params->num_of_eat_finish_philo += 1;
		pthread_mutex_unlock(&philo->params->finish_mutex);
		usleep(philo->params->time_to_eat * 1000);
		pthread_mutex_lock(&philo->params->pickup_fork);
		pthread_mutex_lock(&philo->check_mutex);
		philo->params->forks[philo->left_fork].is_taken = 0;
		philo->params->forks[philo->right_fork].is_taken = 0;
		philo->has_forks = 0;
		pthread_mutex_unlock(&philo->params->pickup_fork);
		pthread_mutex_unlock(&philo->check_mutex);
	}
}

void *philo(void *argv)
{
	t_philo *philo;

	philo = argv;
	while (!philo->params->finish)
	{
		pickup_fork(philo);
		// philo->has_forks
		//thinking(philo);
		eating(philo);
		thinking(philo);
		sleeping(philo);
	}
	return (NULL);
}