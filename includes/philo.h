#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define FT_ERROR 1
#define FT_SUCCESS 0

typedef struct s_philo
{
    int id;
    int num_of_eat;
    int num_of_must_eat;
    int left_fork;
    int right_fork;
    int has_forks;
    struct s_params *params;
    pthread_t thread;
    pthread_mutex_t check_mutex;
    struct timeval last_time_to_eat;
} t_philo;

typedef struct s_fork
{
    int is_taken;
} t_fork;

typedef struct s_params
{
    int num_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nt_must_eat;
    int num_of_eat_finish_philo;
    int finish;
    pthread_mutex_t finish_mutex;
    pthread_mutex_t pickup_fork;
    t_philo *philos;
    t_fork *forks;
    struct timeval create_at;
} t_params;

int init(t_params *param, int ac, char *av[]);
void *ft_calloc(size_t nmemb, size_t size);
void *philo(void *argv);
void *monitor_each_must_eat(void *argv);

void join_and_free_philos(t_params *param);
void create_philos(t_params *params);
void print_state(t_philo *philo, const char *message, int lock);
void *monitor(void *argv);

long long time_to_ms(struct timeval now);

int ft_atoi(const char *str);
int ft_puterror(const char *str);
#endif
