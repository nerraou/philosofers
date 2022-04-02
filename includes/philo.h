#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define EATING 1
#define SLEEPING 2
#define THINKING 3
#define DEAD 0xDEAD

typedef struct s_fork
{
    pthread_mutex_t mutex;
    int fork_id;
    int is_taken;
} t_fork;

typedef struct s_params
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

} t_params;

typedef struct s_philo
{
    t_params *params;
    t_fork *forks;
    pthread_t thread;
    int left_fork;
    int right_fork;
    int philo_id;
    int state;
} t_philo;

void set_params(t_params *param, int ac, char *av[]);
void init_params(t_params *param);
void set_philo(t_philo *philo, t_fork *forks, t_params *params);
void set_forks(t_fork *forks, int size);

int ft_atoi(const char *str);

#endif
