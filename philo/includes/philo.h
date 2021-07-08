#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philo {
	int				id;
	int				last_meal;
	int				cycles;
	void			*a_dress;
	int				rip;
	pthread_mutex_t	*left_frk;
	pthread_mutex_t	*right_frk;
	pthread_mutex_t	*eating;
}	t_philo;

typedef struct s_a {
	struct timeval		base_t;
	int					n_of_philo;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					n_meals;
	int					limitmeal;
	int					deadphilo;
	long unsigned int	start_date;
	int					exit;
	t_philo				philo[200];
	pthread_mutex_t		m_stop;
	pthread_mutex_t		m_write;
}	t_a;

//time and utils
void	ft_cleanexit(t_a *a, char *str);
void	ft_gettime_init(t_a *a);
int		ft_gettime_sincestart(t_a *a);
void	ft_waitfor(t_a *a, int n_ms);
int		ft_atoi(const char *nptr, t_a *a);

//initiators
void	ft_initiator(t_a *a);
void	ft_init_philo(t_a *a, int i);

//threader
void	*ft_threader(void *arg);
void	ft_healthcheck(t_a *a);

#endif