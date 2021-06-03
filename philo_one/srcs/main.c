#include "../includes/philo_one.h"

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
	if (ac == 5)
		a->n_meals = ft_atoi(av[5], a);
	if (ac > 5)
		ft_cleanexit(a, "Too many arguments");
}

int main(int ac, char **av)
{
	t_a	a;
	int	i;
	int	k;
	
	ft_parser(&a, ac, av);
	i = 0;

	while (i < 100)
	{
		usleep(1000000);
		k = gettimeofday(&a.base_t, 0);
		printf("Ladies and gentlemen, the time: %ld \n", a.base_t.tv_sec % 100);
		i++;
	}
}