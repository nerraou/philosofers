/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:20:11 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/10 13:22:22 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_state(pthread_mutex_t *mutex, int state, const char *message)
{
    (void)state;
    pthread_mutex_lock(mutex);
        printf("%s\n", message);
    pthread_mutex_unlock(mutex);
}
