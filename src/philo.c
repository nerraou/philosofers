
#include "philo.h"
///create  two functions 1 generate mutex and destroy mutex

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
        if (philosophers->global_state->philo_is_dead == DEAD)
            print_state(&philosophers->global_state->print_mutex, -1, "someone is dead");
        destroy_mutex(forks, size);
        pthread_mutex_destroy(&state.print_mutex);
        printf("glb state %d", philosophers->global_state->philo_is_dead);
    }
    return 0;
}