/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:08:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/03 17:57:39 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_params(t_params *param)
{
    param->number_of_philosophers = 0;
    param->time_to_die = 0;
    param->time_to_eat = 0;
    param->time_to_sleep = 0;
    param->nt_must_eat = -1;
}
