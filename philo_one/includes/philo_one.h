#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_a {
	struct timeval	base_t;
	int				n_of_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals; 
} t_a;

//utils
int		ft_atoi(const char *nptr, t_a *a);
void	ft_cleanexit(t_a *a, char *str);

#endif