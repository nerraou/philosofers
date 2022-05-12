/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:46:19 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/11 19:04:58 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_params *params)
{
	int				i;
	pthread_t		thread;
	struct timeval	created_at;

	i = 0;
	gettimeofday(&params->create_at, NULL);
	while (i < params->num_of_philosophers)
	{
		params->philos[i].last_time_to_eat = params->create_at;
		pthread_create(&params->philos[i].thread, NULL, philo,
			&params->philos[i]);
		i += 2;
	}
	usleep(100);
	gettimeofday(&created_at, NULL);
	i = 1;
	while (i < params->num_of_philosophers)
	{
		params->philos[i].last_time_to_eat = created_at;
		pthread_create(&params->philos[i].thread, NULL, philo,
			&params->philos[i]);
		i += 2;
	}
	pthread_create(&thread, NULL, monitor, params);
	pthread_detach(thread);
}
