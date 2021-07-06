#include "../includes/philo.h"

void	ft_sanitycheck(t_a *a)
{
	if (a->n_of_philo > 200)
		ft_cleanexit(a, "Error: too many philosophers\n");
	if (a->n_of_philo < 1 || a->t_to_die < 1 || a->t_to_eat < 1 \
	|| a->t_to_sleep < 1 || (a->n_meals < 1 && a->limitmeal == 1))
		ft_cleanexit(a, "Error: check arguments\n");
}

void	init_philo(t_a *a, int i)
{
	a->dude[i].id = i;
	a->dude[i].last_meal = 0;
	a->dude[i].a_dress = (void *)a;
}

void	ft_initmutex(t_a *a)
{
	int				i;
	pthread_mutex_t	fork[200];
	
	i = 0;
	while (i < a->n_of_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		a->dude[i].right_frk = &fork[i];
		if (i == a->n_of_philo - 1)
			a->dude[i].left_frk = &fork[0];
		else
			a->dude[i].left_frk = &fork[i + 1];
		i++;		
	}
}

void	ft_life2(t_a *a, t_dude *dude, int *i)
{
	pthread_mutex_lock(dude->right_frk);
	ft_action(a, dude, "has taken a rfork");
	pthread_mutex_lock(dude->left_frk);
	ft_action(a, dude, "has taken a lfork");
	pthread_mutex_lock(dude->eating);
	dude->last_meal = ft_gettime_sincestart(a);
	pthread_mutex_unlock(dude->eating);
	ft_action(a, dude, "is eating");
	ft_waitfor(a, a->t_to_eat);
	pthread_mutex_unlock(dude->right_frk);
	pthread_mutex_unlock(dude->left_frk);
	ft_action(a, dude, "is sleeping");
	ft_waitfor(a, a->t_to_sleep);
	ft_action(a, dude, "is thinking");
	(dude->cycles)++;
	pthread_lock(&a->m_stop);
	*i = a->dead;
	pthread_unlock(&a->m_stop);
}

void	*ft_life(void *arg)
{
	t_dude	*dude;
	t_a		*a;
	int		i;

	dude = (t_dude *)arg;
	a = (t_a *)dude->a_dress;
	dude->cycles = 0;
	i = 0;
	while ((dude->cycles < a->n_meals || !a->limitmeal) && !i)
		ft_life2(a, dude, &i);
	pthread_mutex_lock(&a->m_stop);
	if (a->dead == 0)
		a->dead = 2;
	pthread_mutex_unlock(&a->m_stop);
	return (NULL);
}
