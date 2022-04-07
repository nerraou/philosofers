
#include "philo.h"
///create  two functions 1 generate mutex and destroy mutex

void init_mutex(t_fork *forks, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        pthread_mutex_init(&forks[i].mutex, NULL);
        i++;
    }
}

// destroy mutex

void destroy_mutex(t_fork *forks, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        pthread_mutex_destroy(&forks[i].mutex);
        i++;
    }
}

void *test(void *philosopher)
{
    t_philo *philo;
    int i;

    i = 0;
    philo = (t_philo *)philosopher;

    printf("HELLO philo number is waiting %d\n your left fork number %d\n your right fork number %d\n ", philo->philo_id, philo->left_fork, philo->right_fork);

    return NULL;
}
// printf("HELLO philo number is EATING %d\n"
//        "your left fork number %d\n"
//        "your right fork number %d\n ",
//        philo->philo_id, philo->left_fork, philo->right_fork);

void *philo_thread(void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    int eat_count;
    eat_count = 0;

    while (philo->state != DEAD && eat_count != philo->params->nt_must_eat)
    {
        pthread_mutex_lock(&philo->forks[philo->left_fork].mutex);
        pthread_mutex_lock(&philo->forks[philo->right_fork].mutex);
        if (!philo->forks[philo->left_fork].is_taken && !philo->forks[philo->right_fork].is_taken)
        {
            philo->forks[philo->left_fork].is_taken = 1;
            philo->forks[philo->right_fork].is_taken = 1;
            philo->state = EATING;
            // philo->eat_time = get_current_time();
        }
        else
            philo->state = SLEEPING;
        pthread_mutex_unlock(&philo->forks[philo->left_fork].mutex);
        pthread_mutex_unlock(&philo->forks[philo->right_fork].mutex);
        if (philo->state == EATING)
        {
            printf("philo number is EATING %d\n", philo->philo_id);
            philo->eat_count++;
            sleep(philo->params->time_to_eat);
            pthread_mutex_lock(&philo->forks[philo->left_fork].mutex);
            pthread_mutex_lock(&philo->forks[philo->right_fork].mutex);
            philo->forks[philo->left_fork].is_taken = 0;
            philo->forks[philo->right_fork].is_taken = 0;
            philo->state = SLEEPING;
            pthread_mutex_unlock(&philo->forks[philo->left_fork].mutex);
            pthread_mutex_unlock(&philo->forks[philo->right_fork].mutex);
        }
        if (philo->state == SLEEPING)
        {
            printf("philo number is SLEEPING %d\n", philo->philo_id);
            sleep(philo->params->time_to_sleep);
            philo->state = THINKING;
        }
        if (philo->state == THINKING)
        {
            printf("philo number is THINKING %d\n", philo->philo_id);
        }
    }
    return NULL;
}

int main(int ac, char *av[])
{
    t_params param;
    t_philo *philosophers;
    t_fork *forks;
    int size;
    int i;

    init_params(&param);
    if (ac == 5 || ac == 6)
    {
        set_params(&param, ac, av);
        size = param.number_of_philosophers;
        philosophers = (t_philo *)malloc(sizeof(t_philo) * size);
        if (!philosophers)
            return 2;
        forks = (t_fork *)malloc(sizeof(t_fork) * size);
        if (!forks)
            return 3;
        set_forks(forks, size);
        set_philo(philosophers, forks, &param);
        init_mutex(forks, size);

        i = 0;
        while (i < size)
        {
            if (pthread_create(&philosophers[i].thread, NULL, philo_thread, (void *)(philosophers + i)) != 0)
                return 2;
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (pthread_join(philosophers[i].thread, NULL) != 0)
                return 2;
            i++;
        }

        destroy_mutex(forks, size);
    }
    return 0;
}