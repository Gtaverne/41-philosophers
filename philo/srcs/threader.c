#include "../includes/philo.h"

void	ft_dialogue(t_a *a, t_philo *philo, char *str)
{
	int	alive;

	pthread_mutex_lock(&a->m_stop);
	alive = a->deadphilo;
	pthread_mutex_unlock(&a->m_stop);
	if (alive == 1)
		return ;
	pthread_mutex_lock(&a->m_write);
	printf("%dms %d %s\n", ft_gettime_sincestart(a), philo->id + 1, str);
	pthread_mutex_unlock(&a->m_write);
}

void	ft_actionlist(t_a *a, t_philo *philo)
{
	pthread_mutex_lock(philo->right_frk);
	ft_dialogue(a, philo, "has taken a fork");
	pthread_mutex_lock(philo->left_frk);
	ft_dialogue(a, philo, "has taken a fork");
	pthread_mutex_lock(philo->eating);
	philo->last_meal = ft_gettime_sincestart(a);
	ft_dialogue(a, philo, "is eating");
	pthread_mutex_unlock(philo->eating);
	ft_waitfor(a, a->t_to_eat);
	pthread_mutex_unlock(philo->left_frk);
	pthread_mutex_unlock(philo->right_frk);
	ft_dialogue(a, philo, "is sleeping");
	ft_waitfor(a, a->t_to_sleep);
	ft_dialogue(a, philo, "is thinking");
	philo->cycles++;
	pthread_mutex_lock(&a->m_stop);
	philo->rip = a->deadphilo;
	pthread_mutex_unlock(&a->m_stop);
}

void	*ft_threader(void *arg)
{
	t_philo	*philo;
	t_a		*a;

	philo = (t_philo *)arg;
	a = (t_a *)philo->a_dress;
	philo->rip = 0;
	while ((philo->cycles < a->n_meals || a->limitmeal == 0) && !philo->rip)
		ft_actionlist(a, philo);
	pthread_mutex_lock(&a->m_stop);
	if (a->deadphilo == 0)
		a->deadphilo = 2;
	if (a->deadphilo == 2)
		a->deadphilo = 3;
	pthread_mutex_unlock(&a->m_stop);
	return (NULL);
}

void	ft_healthcheck(t_a *a)
{
	int	now;
	int	datelastmeal;
	int	i;

	i = -1;
	now = ft_gettime_sincestart(a);
	while (++i < a->n_of_philo)
	{
		pthread_mutex_lock(a->philo[i].eating);
		datelastmeal = a->philo[i].last_meal;
		pthread_mutex_unlock(a->philo[i].eating);
		if (now - datelastmeal > a->t_to_die)
		{
			pthread_mutex_lock(&a->m_write);
			printf("%dms %d is dead\n", ft_gettime_sincestart(a), i + 1);
			pthread_mutex_unlock(&a->m_write);
			pthread_mutex_lock(&a->m_stop);
			if (a->deadphilo == 0)
				a->deadphilo = 1;
			pthread_mutex_unlock(&a->m_stop);
			return ;
		}
	}
}
