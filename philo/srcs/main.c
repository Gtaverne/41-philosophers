#include "../includes/philo.h"

void	ft_parser(t_a *a, int ac, char **av)
{
	if (ac < 5)
	{
		printf("Il manque des arguments :\n- N of philo\n\
- Time to die\n- Time to eat\n- Time to sleep\n[- Time each \
philosopher must eat]\n");
		exit(1);
	}
	a->n_of_philo = ft_atoi(av[1], a);
	a->t_to_die = ft_atoi(av[2], a);
	a->t_to_eat = ft_atoi(av[3], a);
	a->t_to_sleep = ft_atoi(av[4], a);
	if (ac == 6)
	{
		a->n_meals = ft_atoi(av[5], a);
		a->limitmeal = 1;
	}
	if (ac == 5)
	{
		a->limitmeal = 0;
		a->n_meals = -1;
	}
	if (ac > 6)
		ft_cleanexit(a, "Too many arguments");
	ft_sanitycheck(a);
}

int main(int ac, char **av)
{
	t_a			a;
	pthread_t	thread[200];
	int			i;
	
	ft_parser(&a, ac, av);
	ft_initmutex(&a);
	i = 0;

	while (i < a.n_of_philo)
	{
		init_philo(&a, i);
		pthread_create(&thread[i], NULL, ft_life, &a.dude[i]);
		i = i + 2;
		if (i >= a.n_of_philo && i % 2 == 0)
		{
			i = 1;
			usleep(500);
		}
		i++;
	}
	while (!a.dead)
		ft_checkhealth(&a);
	i = 0;
	while (i < a.n_of_philo)
		pthread_join(thread[i++], NULL);
	return (0);
}