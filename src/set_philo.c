/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:46:28 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/08 14:37:53 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_philo(t_philo *philo, t_fork *forks, t_params *params, t_state *state)
{
    int i;
    int j;
    int size;

    size = params->number_of_philosophers;
    j = 1;
    i = 0;
    while (i < size)
    {
        philo[i].params = params;
        philo[i].forks = forks;
        philo[i].global_state = state;
        philo[i].left_fork = forks[j - 1].fork_id;
        if (j == size)
            philo[i].right_fork = forks[0].fork_id;
        else
            philo[i].right_fork = forks[j].fork_id;
        philo[i].philo_id = j;
        philo[i].eat_count = 0;
        philo[i].eat_time = get_current_time();
        j++;
        i++;
    }
}