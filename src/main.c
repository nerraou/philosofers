#include "philo.h"


int main(int ac, char *av[])
{
    t_params param;
    if (ac != 5 && ac != 6)
        return (ft_puterror("ERROR: wrong argument count\n"));
    memset(&param, 0, sizeof(t_params));
    if(init(&param, ac, av))
    {
        printf("ERROR\n");
        return 1;
    }
    printf("OK\n");
    return (0);
}