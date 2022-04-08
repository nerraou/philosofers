
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

void print_state(pthread_mutex_t *mutex, int state, const char *message)
{
    pthread_mutex_lock(mutex);
    if (state != DEAD)
        printf("%s\n", message);
    pthread_mutex_unlock(mutex);
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
    while (philo->global_state->philo_is_dead != DEAD)
    {
        pthread_mutex_lock(&philo->forks[philo->left_fork].mutex);
        pthread_mutex_lock(&philo->forks[philo->right_fork].mutex);
        if (!philo->forks[philo->left_fork].is_taken && !philo->forks[philo->right_fork].is_taken)
        {
            philo->forks[philo->left_fork].is_taken = 1;
            philo->forks[philo->right_fork].is_taken = 1;
            philo->state = EATING;
            philo->eat_time = get_current_time();
        }
        else
            philo->state = SLEEPING;
        pthread_mutex_unlock(&philo->forks[philo->left_fork].mutex);
        pthread_mutex_unlock(&philo->forks[philo->right_fork].mutex);
        if (philo->state == EATING)
        {
            print_state(&philo->global_state->print_mutex, philo->global_state->philo_is_dead, "philo number is EATING");
            philo->eat_count++;
            usleep(philo->params->time_to_eat * 1000);
            pthread_mutex_lock(&philo->forks[philo->left_fork].mutex);
            pthread_mutex_lock(&philo->forks[philo->right_fork].mutex);
            philo->forks[philo->left_fork].is_taken = 0;
            philo->forks[philo->right_fork].is_taken = 0;
            philo->state = SLEEPING;
            pthread_mutex_unlock(&philo->forks[philo->left_fork].mutex);
            pthread_mutex_unlock(&philo->forks[philo->right_fork].mutex);
        }
        if (get_current_time() - philo->eat_time >= philo->params->time_to_die)
        {
            print_state(&philo->global_state->print_mutex, philo->global_state->philo_is_dead, "philo is dead");
            philo->state = DEAD;
            if (philo->global_state->philo_is_dead != DEAD)
                philo->global_state->philo_is_dead = DEAD;
        }
        if (philo->state == SLEEPING)
        {
            print_state(&philo->global_state->print_mutex, philo->global_state->philo_is_dead, "philo number is SLEEPING");
            usleep(philo->params->time_to_sleep * 1000);
            philo->state = THINKING;
        }
        if (philo->state == THINKING)
        {
            print_state(&philo->global_state->print_mutex, philo->global_state->philo_is_dead, "philo number is THINKING");
        }
    }
    return NULL;
}

int main(int ac, char *av[])
{
    t_params param;
    t_state state;
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
        global_state(&state);
        set_philo(philosophers, forks, &param, &state);
        init_mutex(forks, size);
        pthread_mutex_init(&state.print_mutex, NULL);
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
        pthread_mutex_destroy(&state.print_mutex);
        printf("glb state %d", philosophers->global_state->philo_is_dead);
    }
    return 0;
}