#include "../includes/philo_one.h"

void	ft_cleanexit(t_a *a, char *str)
{
	printf("Exit : %s\n", str);
	a->n_of_philo = 0;
	exit(0);
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
