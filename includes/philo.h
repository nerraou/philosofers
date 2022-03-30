#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef struct s_params
{
    int number_of_philosophers;
    int *forks;
    int philo_id;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

} t_params;

void set_params(t_params *param, int ac, char *av[]);
void init_params(t_params *param);

void set_forks(int *forks, int size);

int ft_atoi(const char *str);

#endif
