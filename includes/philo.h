#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define EATING 1
#define SLEEPING 2
#define THINKING 3
#define DEAD 4

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
    int nt_must_eat;

} t_params;

typedef struct s_state
{
    int philo_is_dead;
    int satiation;
    pthread_mutex_t print_mutex;
} t_state;

typedef struct s_philo
{
    t_params *params;
    t_fork *forks;
    t_state *global_state;
    pthread_t thread;
    int left_fork;
    int right_fork;
    int philo_id;
    int eat_count;
    int last_eat_time;
    int state;
    long eat_time;
} t_philo;

void set_params(t_params *param, int ac, char *av[]);
void init_params(t_params *param);
void set_philo(t_philo *philo, t_fork *forks, t_params *params, t_state *state);
void set_forks(t_fork *forks, int size);
void global_state(t_state *global_state);

long get_current_time();
int ft_atoi(const char *str);

#endif
