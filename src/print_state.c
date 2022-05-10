/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:20:11 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/10 18:40:35 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_state(t_philo *philo, const char *message, int lock)
{
      long long ms;
      struct timeval now;

      if (lock == 1)
      {
            pthread_mutex_lock(&philo->params->finish_mutex);
      }
      gettimeofday(&now, NULL);
      ms = time_to_ms(now) - time_to_ms(philo->params->create_at);
      if (!philo->params->finish)
            printf("%lld\t%d\t %s\n", ms, philo->id + 1, message);
      if (lock == 1)
      {
            pthread_mutex_unlock(&philo->params->finish_mutex);
      }
}
