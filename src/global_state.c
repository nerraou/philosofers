/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:14:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/08 14:16:20 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void global_state(t_state *global_state)
{
    global_state->philo_is_dead = -1;
    global_state->satiation = -1;
}