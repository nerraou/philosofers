#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct s_philo
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    
} t_philo;

void set_philo(t_philo *philo, int ac,char *av[]);
void init_philo(t_philo *philo);
int	ft_atoi(const char *str);

#endif
