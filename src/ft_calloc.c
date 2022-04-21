#include "philo.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
    memset(arr, 0,  nmemb * size);
	return (arr);
}
