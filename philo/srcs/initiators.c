#include "../includes/philo.h"

void	ft_initforks(t_a *a)
{
	int				i;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	m_eating[200];

	i = 0;
	while (i < a->n_of_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		pthread_mutex_init(&m_eating[i], NULL);
		a->philo[i].right_frk = &fork[i];
		a->philo[i].eating = &m_eating[i];
		if (i == a->n_of_philo - 1)
			a->philo[i].left_frk = &fork[0];
		else
			a->philo[i].left_frk = &fork[i + 1];
		i++;
	}
}

void	ft_initiator(t_a *a)
{
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_write;

	a->deadphilo = 0;
	ft_gettime_init(a);
	pthread_mutex_init(&m_stop, NULL);
	pthread_mutex_init(&m_write, NULL);
	a->m_stop = m_stop;
	a->m_write = m_write;
	if (a->n_of_philo == 1)
	{
		printf("%dms %d %s\n", ft_gettime_sincestart(a), 1, "has taken a fork");
		ft_waitfor(a, a->t_to_die);
		printf("%dms %d %s\n", ft_gettime_sincestart(a), 1, "died alone");
		ft_cleanexit(a, "ending alone");
	}
	ft_initforks(a);
}

void	ft_init_philo(t_a *a, int i)
{
	a->philo[i].id = i;
	a->philo[i].cycles = 0;
	a->philo[i].last_meal = 0;
	a->philo[i].a_dress = (void *)a;
	a->exit = 0;
}
