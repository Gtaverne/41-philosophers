#include "../includes/philo.h"

void	ft_initforks(t_a *a)
{
	int				i;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	m_eating[200];
	
	i = 0;
	ft_gettime_init(a);
	while (i < a->n_of_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		a->philo[i].eating = &m_eating[i];
		a->philo[i].left_frk = &fork[i];
		if (i == a->n_of_philo - 1)
			a->philo[i].right_frk = &fork[0];
		else
			a->philo[i].right_frk = &fork[i + 1];
		i++;		
	}
}

void	ft_initiator(t_a *a)
{
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_write;

	a->deadphilo = 0;
	pthread_mutex_init(&m_stop, NULL);
	pthread_mutex_init(&m_write, NULL);
	a->m_stop = m_stop;
	a->m_write = m_write;
	ft_initforks(a);
}

void	ft_init_philo(t_a *a, int i)
{
	a->philo[i].id = i;
	a->philo[i].last_meal = 0;
	a->philo[i].a_dress = (void *)a;
}