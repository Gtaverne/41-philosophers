#include "../includes/philo.h"

void	ft_action(t_a *a, t_dude *dude, char *str)
{
	int	i;

	pthread_mutex_lock(&a->m_stop);
	i = a->dead;
	pthread_mutex_unlock(&a->m_stop);
	if (i == 1)
		return ;
	pthread_mutex_lock(&a->m_write);
	printf("%dms %d %s\n", ft_gettime_sincestart(a), dude->id + 1,\
	str);
	pthread_mutex_unlock(&a->m_write);
}
