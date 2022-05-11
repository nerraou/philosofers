/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:43:06 by nerraou           #+#    #+#             */
/*   Updated: 2022/05/11 17:05:29 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define FT_ERROR 1
# define FT_SUCCESS 0

typedef struct s_philo
{
	int				id;
	int				num_of_eat;
	int				num_of_must_eat;
	int				left_fork;
	int				right_fork;
	int				has_forks;
	struct s_params	*params;
	pthread_t		thread;
	pthread_mutex_t	check_mutex;
	struct timeval	last_time_to_eat;
}					t_philo;

typedef struct s_fork
{
	int				is_taken;
	pthread_mutex_t	fork_mutex;
}				t_fork;

typedef struct s_params
{
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nt_must_eat;
	int				num_of_eat_finish_philo;
	int				finish;
	pthread_mutex_t	finish_mutex;
	t_philo			*philos;
	t_fork			*forks;
	struct timeval	create_at;
}				t_params;

void		*ft_calloc(size_t nmemb, size_t size);
void		*philo(void *argv);
void		*monitor_each_must_eat(void *argv);
void		*monitor(void *argv);

void		join_and_free_philos(t_params *param);
void		create_philos(t_params *params);
void		print_state(t_philo *philo, const char *message, int lock);

int			init(t_params *param, int ac, char *av[]);
int			ft_atoi(const char *str);
int			ft_puterror(const char *str);
long long	time_to_ms(struct timeval now);

#endif
