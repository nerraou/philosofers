#include "philo.h"

int ft_puterror(const char *str)
{
    int i;

    i = 0;
    while (str[i++])
        i++;
    write(2 ,str, i);
        return (1); 
}