/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:09:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/04/03 15:18:34 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	parsing_arg(t_params *param, int ac, char *av[])
{
  param->num_of_philosophers = ft_atoi(av[1]);
    param->time_to_die = ft_atoi(av[2]);
    param->time_to_eat = ft_atoi(av[3]);
    param->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        param->nt_must_eat = ft_atoi(av[5]);
}

static int check_info(t_params *param, int ac)
{
    if (ac == 6 && param->nt_must_eat <= 0)
    return (ft_puterror("ERROR: wrong num of must eat\n"));
    if (param->num_of_philosophers < 0)
    return (ft_puterror("ERROR: wrong num of philosophers\n"));
    if (param->time_to_die < 0)
    return (ft_puterror("ERROR: wrong time to die\n"));
    if (param->time_to_eat < 0)
    return (ft_puterror("ERROR: wrong time to eat\n"));
    if (param->time_to_sleep < 0)
    return (ft_puterror("ERROR: wrong time to sleep \n"));
    return (FT_SUCCESS);
}

static  int set_philo(t_params *param)
{
    int i;

    pthread_mutex_init(&param->finish_mutex, NULL);
    param->philos = ft_calloc(param->num_of_philosophers, sizeof(t_philo));
    if (!param->philos)
        return (ft_puterror("ERROR: malloc failed\n"));
    param->forks = ft_calloc(param->num_of_philosophers, sizeof(t_fork));
    if (!param->forks)
    {     free(param->philos);
         return (ft_puterror("ERROR: malloc failed\n"));
    }
    i = 0;
    while (i < param->num_of_philosophers)
    {
        param->philos[i].id = i;
        pthread_mutex_init(&param->philos[i].check_mutex, NULL);
        if (i == 0)
         param->philos[i].left_fork = param->num_of_philosophers - 1;
        else
          param->philos[i].left_fork = i - 1;
        param->philos[i].right_fork = i;
        param->philos[i].params = param;
        i++;
    }
    return (FT_SUCCESS);    

}
int init(t_params *param, int ac, char *av[])
{
  parsing_arg(param, ac, av);
  if (check_info(param, ac))
    return(FT_ERROR);
  if (set_philo(param))
    return(FT_ERROR);
return(FT_SUCCESS);
}
