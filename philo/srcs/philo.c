#include "../includes/philo.h"

void	ft_sanitycheck(t_a *a)
{
	if (a->n_of_philo > 200)
		ft_cleanexit(a, "Error: too many philosophers\n");
	if (a->n_of_philo < 1 || a->t_to_die < 1 || a->t_to_eat < 1 \
	|| a->t_to_sleep < 1 || (a->n_meals < 1 && a->limitmeal == 1))
		ft_cleanexit(a, "Error: check arguments\n");
}

void	ft_parser(t_a *a, int ac, char **av)
{
	if (ac < 5)
	{
		printf("Il manque des arguments :\n- N of philo\n\
- Time to die\n- Time to eat\n- Time to sleep\n- Time each \
philosopher must eat [option]\n");
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
		ft_cleanexit(a, ": too many arguments");
	ft_sanitycheck(a);
}

int	main(int ac, char **av)
{
	t_a			a;
	pthread_t	thread[200];
	int			i;

	ft_parser(&a, ac, av);
	i = 0;
	ft_initiator(&a);
	while (i < a.n_of_philo)
	{
		ft_init_philo(&a, i);
		pthread_create(&thread[i], NULL, ft_threader, &a.philo[i]);
		i = i + 2;
		if (i >= a.n_of_philo && i % 2 == 0)
		{
			i = 1;
			usleep(250);
		}
	}
	while (!a.deadphilo)
		ft_healthcheck(&a);
	i = 0;
	while (i < a.n_of_philo)
		pthread_join(thread[i++], NULL);
	ft_cleanexit(&a, "end");
	return (0);
}
