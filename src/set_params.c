/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:09:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/03/30 17:09:53 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
 
void *memset(void *s, int c, size_t n);
*/
void set_params(t_params *param, int ac, char *av[])
{
    int f_size;

    f_size = ft_atoi(av[1]);
    param->number_of_philosophers = f_size;
    set_forks(param->forks, f_size);
    param->philo_id = 1;
    param->time_to_die = ft_atoi(av[2]);
    param->time_to_eat = ft_atoi(av[3]);
    param->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        param->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}
