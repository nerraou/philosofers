/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_free_philos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:43:13 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/11 17:43:37 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_and_free_philos(t_params *param)
{
	int	i;

	i = 0;
	while (i < param->num_of_philosophers)
	{
		pthread_join(param->philos[i].thread, NULL);
		pthread_mutex_destroy(&param->philos[i].check_mutex);
		pthread_mutex_destroy(&param->forks[i].fork_mutex);
		i++;
	}
	pthread_mutex_destroy(&param->finish_mutex);
	free(param->philos);
	free(param->forks);
}
