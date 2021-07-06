#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_dude {
	int				id;
	int				last_meal;
	int				cycles;
	void			*a_dress;
	pthread_mutex_t	*left_frk;
	pthread_mutex_t	*right_frk;
	pthread_mutex_t	*eating;
}	t_dude;

typedef struct s_a {
	struct timeval		base_t;
	int					n_of_philo;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					n_meals;
	int					limitmeal;
	int					dead;
	time_t				sec_start;
	suseconds_t			usec_start;
	long unsigned int	start_date;
	int					error;
	t_dude				dude[200];
	pthread_mutex_t		m_stop;
	pthread_mutex_t		m_write;
}	t_a;

//utils
void	ft_gettime_init(t_a *a);
int		ft_gettime_sincestart(t_a *a);
void	ft_waitfor(t_a *a, int n_ms);
int		ft_atoi(const char *nptr, t_a *a);
void	ft_cleanexit(t_a *a, char *str);

//utils2
void	ft_sanitycheck(t_a *a);
void	ft_initmutex(t_a *a);
void	init_philo(t_a *a, int i);
void	*ft_life(void *arg);
void	ft_life2(t_a *a, t_dude *dude, int *i);

//utils3
void	ft_action(t_a *a, t_dude *dude, char *str);
void	ft_philodoes(t_a *a, int id, int time, char *action);

#endif