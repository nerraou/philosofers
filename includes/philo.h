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
    struct s_params *params;
    pthread_t   thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t	check_mutex;
    struct timeval  last_time_to_eat;
} t_philo;


typedef struct s_params
{
    int             num_of_philosophers;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             nt_must_eat;
    int             finish;
    pthread_mutex_t finish_mutex;
    t_philo         *philos;
    pthread_mutex_t *forks;
    struct timeval  create_at;
}              t_params;

int init(t_params *param, int ac, char *av[]);
void	*ft_calloc(size_t nmemb, size_t size);


void print_state(pthread_mutex_t *mutex, int state, const char *message);
void *philo_thread(void *philosopher);

long get_current_time();
int ft_atoi(const char *str);
int ft_puterror(const char *str);
#endif
