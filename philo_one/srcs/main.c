#include "../includes/philo_one.h"

void	ft_parser(t_a *a, int ac, char **av)
{
	if (ac < 5)
	{
		printf("Not enough arguments\n");
		exit(1);
	}
}

int main(int ac, char **av)
{
	t_a *a;
	
	ft_parser(&a, ac, av);
}