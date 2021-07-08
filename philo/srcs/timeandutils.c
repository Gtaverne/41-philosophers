#include "../includes/philo.h"

void	ft_cleanexit(t_a *a, char *str)
{
	int	i;

	i = 0;
	a->n_of_philo = -1;
	a->deadphilo = 0;
	printf("Exit : %s\n", str);
	a->exit = 1;
}

void	ft_gettime_init(t_a *a)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	a->start_date = t.tv_sec * 1000 + t.tv_usec / 1000;
}

int	ft_gettime_sincestart(t_a *a)
{
	struct timeval	t;
	int				res;

	gettimeofday(&t, NULL);
	res = t.tv_sec * 1000 + t.tv_usec / 1000 - a->start_date;
	return (res);
}

void	ft_waitfor(t_a *a, int n_ms)
{
	int	start;
	int	current;

	start = ft_gettime_sincestart(a);
	current = start;
	while (current < start + n_ms)
	{
		usleep(100);
		current = ft_gettime_sincestart(a);
	}
}

int	ft_atoi(const char *nptr, t_a *a)
{
	int			i;
	long int	r;

	i = 0;
	r = 0;
	while (nptr && nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			r = r * 10 + nptr[i] - '0';
		else
		{
			ft_cleanexit(a, "Arguments non numeriques");
			printf("  Correct %s\n", nptr);
			return (0);
		}
		i++;
	}
	if (r >= 3600000)
		ft_cleanexit(a, "Valeur enorme, on va attendre des heures...");
	return ((int)r);
}
