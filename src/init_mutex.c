/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:33:06 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/10 12:33:52 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_mutex(t_fork *forks, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        pthread_mutex_init(&forks[i].mutex, NULL);
        i++;
    }
}