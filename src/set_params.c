/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:09:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/03 15:18:34 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_params(t_params *param, int ac, char *av[])
{
    param->number_of_philosophers = ft_atoi(av[1]);
    param->time_to_die = ft_atoi(av[2]);
    param->time_to_eat = ft_atoi(av[3]);
    param->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        param->nt_must_eat = ft_atoi(av[5]);
}
