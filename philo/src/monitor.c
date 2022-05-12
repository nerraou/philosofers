/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:11:56 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/11 18:22:21 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_philo(t_philo *philo, t_params *params)
{
	struct timeval	now;
	long long		ms;

	pthread_mutex_lock(&philo->check_mutex);
	gettimeofday(&now, NULL);
	ms = time_to_ms(now) -\
		(time_to_ms(philo->last_time_to_eat) + params->time_to_die);
	pthread_mutex_lock(&philo->params->finish_mutex);
	if (ms >= 0 && philo->params->finish == 0)
	{
		print_state(philo, "died", 0);
		philo->params->finish = 1;
	}
	if (params->nt_must_eat > 0
		&& params->num_of_eat_finish_philo == params->num_of_philosophers)
		params->finish = 1;
	pthread_mutex_unlock(&philo->params->finish_mutex);
	pthread_mutex_unlock(&philo->check_mutex);
}

void	*monitor(void *argv)
{
	t_params		*params;
	t_philo			*philo;
	int				i;

	params = argv;
	while (!params->finish)
	{
		i = 0;
		while (i < params->num_of_philosophers)
		{
			philo = &params->philos[i];
			monitor_philo(philo, params);
			i++;
		}
	}
	return (NULL);
}
