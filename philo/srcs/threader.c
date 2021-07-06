#include "../includes/philo.h"

void	ft_dialogue(t_a *a, t_philo *philo, char *str)
{
	int	alive;

	pthread_mutex_lock(&a->m_stop);
	alive = a->deadphilo;
	pthread_mutex_unlock(&a->m_stop);
	if (alive)
		return ;
	pthread_mutex_lock(&a->m_write);
	printf("%dms %d %s\n", ft_gettime_sincestart(a), philo->id + 1, str);
	pthread_mutex_unlock(&a->m_write);
}

void	ft_actionlist(t_a *a, t_philo *philo)
{
	pthread_mutex_lock(philo->left_frk);
	ft_dialogue(a, philo, "has taken a lfork");
	pthread_mutex_lock(philo->right_frk);
	ft_dialogue(a, philo, "has taken a rfork");
	pthread_mutex_lock(philo->eating);
	philo->last_meal = ft_gettime_sincestart(a);
	ft_dialogue(a, philo, "is eating");
	ft_waitfor(a, a->t_to_eat);
	pthread_mutex_unlock(philo->left_frk);
	pthread_mutex_unlock(philo->right_frk);
	pthread_mutex_unlock(philo->eating);
	ft_dialogue(a, philo, "is sleeping");
	ft_waitfor(a, a->t_to_sleep);
	ft_dialogue(a, philo, "is thinking");
	ft_waitfor(a, a->t_to_sleep);
	philo->cycles++;
	//penser a proteger ca
	philo->rip = a->deadphilo;
}

void	*ft_threader(void *arg)
{
	t_philo	*philo;
	t_a		*a;

	philo = (t_philo *)arg;
	a = (t_a *)philo->a_dress;
	philo->cycles = 0;
	philo->rip = 0;
	while (!philo->rip && (philo->cycles < a->n_meals || a->limitmeal == 0))
		ft_actionlist(a, philo);
	return (NULL);
}