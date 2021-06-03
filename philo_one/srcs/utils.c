#include "../includes/philo_one.h"

void	ft_cleanexit(t_a *a, char *str)
{
	printf("Exit : %s\n", str);
	exit(0);
}

int	ft_atoi(const char *nptr, t_a *a)
{
	long long int		i;
	long long int		r;

	i = 0;
	r = 0;
	while (nptr[i] != '\0')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			r = r * 10 + nptr[i] - '0';
		else if (nptr[i] == 0)
			break ;
		else
			ft_cleanexit(a, "Non numerical argument");
		i++;
	}
	if (r >= 36000000)
		ft_cleanexit(a, "Valeur enorme, on va attendre mille ans...");
	return (r);
}
