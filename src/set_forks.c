/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:14:53 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/02 17:54:12 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_forks(t_fork *forks, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        forks[i].fork_id = i;
        forks[i].is_taken = 0;
        i++;
    }
}