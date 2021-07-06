#include "../includes/philo.h"

void	ft_cleanexit(t_a *a, char *str)
{
	printf("Exit : %s\n", str);
	a->n_of_philo = 0;
	exit(0);
}

void	ft_gettime_init(t_a *a)
{
	struct timeval t;
	
	gettimeofday(&t, NULL);
	a->sec_start = t.tv_sec;
	a->usec_start = t.tv_usec;
	a->start_date = a->sec_start * 1000 + a->usec_start / 1000;
}

int		ft_gettime_sincestart(t_a *a)
{
	struct timeval	t;
	int				res;

	gettimeofday(&t, NULL);
	res = t.tv_sec * 1000 + t.tv_usec / 1000 - a->sec_start;
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
		usleep(50);
		current = ft_gettime_sincestart(a);
	}
}

int	ft_atoi(const char *nptr, t_a *a)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (nptr && nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			r = r * 10 + nptr[i] - '0';
		else
			ft_cleanexit(a, "Arguments non numeriques");
		i++;
	}
	if (r >= 3600000)
		ft_cleanexit(a, "Valeur enorme, on va attendre des heures...");
	return (r);
}
