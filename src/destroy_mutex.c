/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:38:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/10 12:39:00 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_mutex(t_fork *forks, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        pthread_mutex_destroy(&forks[i].mutex);
        i++;
    }
}
