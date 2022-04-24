/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:59:07 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/08 16:00:39 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long time_to_ms(struct timeval now)
{
   long long    ms;

   ms = now.tv_sec * 1000;
   ms += now.tv_usec / 1000;
   return (ms);
}