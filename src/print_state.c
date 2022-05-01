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

void print_state(t_philo *philo, const char *message)
{
      long long ms;
      struct timeval now;

      pthread_mutex_lock(&philo->params->finish_mutex);
      gettimeofday(&now, NULL);
      ms = time_to_ms(now) ;
      if (!philo->params->finish)
            printf("%lld\t%d\t %s\n", ms, philo->id + 1, message);
      pthread_mutex_unlock(&philo->params->finish_mutex);
}
