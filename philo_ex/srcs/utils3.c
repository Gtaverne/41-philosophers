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

void	ft_healthcheck(t_a *a)
{
	int	i;
	int now;
	int	datelastmeal;

	i = -1;
	now = ft_gettime_sincestart(a);
	while (++i < a->n_of_philo)
	{
		pthread_mutex_lock(a->dude[i].eating);
		datelastmeal = a->dude[i].last_meal;
		pthread_mutex_unlock(a->dude[i].eating);
		if (datelastmeal + a->t_to_die > now)
		{
			pthread_mutex_lock(&a->m_write);
			printf("%dms %d is dead\n", ft_gettime_sincestart(a), i + 1);
			pthread_mutex_unlock(&a->m_write);
			pthread_mutex_lock(&a->m_stop);
			if (a->dead == 2)
				a->dead = 3;
			if (a->dead == 0)
				a->dead = 1;
			pthread_mutex_unlock(&a->m_stop);
			return ;
		}
	}
}

void	ft_sanitycheck(t_a *a)
{
	if (a->n_of_philo > 200)
		ft_cleanexit(a, "Error: too many philosophers\n");
	if (a->n_of_philo < 1 || a->t_to_die < 1 || a->t_to_eat < 1 \
	|| a->t_to_sleep < 1 || (a->n_meals < 1 && a->limitmeal == 1))
		ft_cleanexit(a, "Error: check arguments\n");
	ft_initall(a);
}
