/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:18:47 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/11 18:09:18 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_params	param;

	if (ac != 5 && ac != 6)
		return (ft_puterror("ERROR: wrong argument count\n"));
	memset(&param, 0, sizeof(t_params));
	if (init(&param, ac, av))
		return (FT_ERROR);
	create_philos(&param);
	join_and_free_philos(&param);
	return (FT_SUCCESS);
}
