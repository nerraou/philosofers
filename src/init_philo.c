/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:08:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/03/28 15:30:51 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_philo *philo)
{
    philo->number_of_philosophers = 0;
    philo->time_to_die = 0;
    philo->time_to_eat = 0;
    philo->time_to_sleep = 0;
    philo->number_of_times_each_philosopher_must_eat = -1;
}
