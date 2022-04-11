/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:25:35 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/10 16:45:18 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    int eat_count;
    eat_count = 0;
    while (philo->global_state->philo_is_dead != DEAD)
    {

        pthread_mutex_lock(&philo->forks[philo->left_fork].mutex);
        pthread_mutex_lock(&philo->forks[philo->right_fork].mutex);
        if (!philo->forks[philo->left_fork].is_taken && !philo->forks[philo->right_fork].is_taken)
        {
            philo->forks[philo->left_fork].is_taken = 1;
            philo->forks[philo->right_fork].is_taken = 1;
            philo->state = EATING;
            philo->eat_time = get_current_time();
        }
        else
            philo->state = SLEEPING;
        pthread_mutex_unlock(&philo->forks[philo->left_fork].mutex);
        pthread_mutex_unlock(&philo->forks[philo->right_fork].mutex);
        if (philo->state == EATING)
        {
            print_state(&philo->global_state->print_mutex, philo->global_state->philo_is_dead, "philo number is EATING");
            philo->eat_count++;
            usleep(philo->params->time_to_eat * 1000);
            pthread_mutex_lock(&philo->forks[philo->left_fork].mutex);
            pthread_mutex_lock(&philo->forks[philo->right_fork].mutex);
            philo->forks[philo->left_fork].is_taken = 0;
            philo->forks[philo->right_fork].is_taken = 0;
            philo->state = SLEEPING;
            pthread_mutex_unlock(&philo->forks[philo->left_fork].mutex);
            pthread_mutex_unlock(&philo->forks[philo->right_fork].mutex);
        }
        if (get_current_time() - philo->eat_time >= philo->params->time_to_die)
        {
            philo->state = DEAD;
            philo->global_state->philo_is_dead = DEAD;
            // printf("%s\n", "philo is dead");
            // print_state(&philo->global_state->print_mutex, philo->global_state->philo_is_dead, );
        }
        if (philo->state == SLEEPING)
        {
            print_state(&philo->global_state->print_mutex, philo->global_state->philo_is_dead, "philo number is SLEEPING");
            usleep(philo->params->time_to_sleep * 1000);
            philo->state = THINKING;
        }
        if (philo->state == THINKING)
        {
            print_state(&philo->global_state->print_mutex, philo->global_state->philo_is_dead, "philo number is THINKING");
        }
    }
    return NULL;
}