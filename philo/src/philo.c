/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:52:08 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/11 18:57:36 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	pickup_fork(t_philo *philo)
{
	t_fork	*left;
	t_fork	*right;

	right = &philo->params->forks[philo->right_fork];
	left = &philo->params->forks[philo->left_fork];
	pthread_mutex_lock(&right->fork_mutex);
	if (!right->is_taken)
	{
		philo->params->forks[philo->right_fork].is_taken = 1;
		philo->has_forks++;
		print_state(philo, "has taken a fork", 1);
	}
	pthread_mutex_unlock(&right->fork_mutex);
	pthread_mutex_lock(&left->fork_mutex);
	if (!left->is_taken)
	{
		philo->params->forks[philo->left_fork].is_taken = 1;
		philo->has_forks++;
		print_state(philo, "has taken a fork", 1);
	}
	pthread_mutex_unlock(&left->fork_mutex);
	if (philo->has_forks == 2)
		return (1);
	return (0);
}

static void	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping", 1);
	usleep(philo->params->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	print_state(philo, "is thinking", 1);
}

static void	eating(t_philo *philo)
{
	if (philo->has_forks == 2)
	{
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->params->finish_mutex);
		print_state(philo, "is eating", 0);
		gettimeofday(&philo->last_time_to_eat, NULL);
		philo->num_of_eat += 1;
		if (philo->num_of_eat == philo->params->nt_must_eat)
			philo->params->num_of_eat_finish_philo += 1;
		philo->has_forks = 0;
		pthread_mutex_unlock(&philo->params->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
		usleep(philo->params->time_to_eat * 1000);
		pthread_mutex_lock(&philo->params->forks[philo->right_fork].fork_mutex);
		philo->params->forks[philo->right_fork].is_taken = 0;
		pthread_mutex_unlock(&philo->params->forks
		[philo->right_fork].fork_mutex);
		pthread_mutex_lock(&philo->params->forks
		[philo->left_fork].fork_mutex);
		philo->params->forks[philo->left_fork].is_taken = 0;
		pthread_mutex_unlock(&philo->params->forks
		[philo->left_fork].fork_mutex);
	}
}

void	*philo(void *argv)
{
	t_philo	*philo;

	philo = argv;
	while (1)
	{
		pthread_mutex_lock(&philo->params->finish_mutex);
		if (philo->params->finish)
		{
			pthread_mutex_unlock(&philo->params->finish_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->params->finish_mutex);
		if (pickup_fork(philo))
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	return (NULL);
}
