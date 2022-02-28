/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:20:37 by decordel          #+#    #+#             */
/*   Updated: 2022/03/01 02:03:45 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define RED_ERR "\033[1;31m"
# define DEF "\033[0;0m"
# define SEM_FORK "decordel_fork_sem"
# define SEM_CHECK_ATE "decordel_ate_sem"
# define SEM_CHECK_DEAD "decordel_dead_sem"
# include <libc.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				n_p;
	pid_t			pid;
	pthread_t		tid;
	int				fork_free;
	int				count_eat;
	int				last_eat;
	struct s_philo	*next;

}					t_philo;

typedef struct s_fork
{
	sem_t			*forks;
	sem_t			*all_ate;
	sem_t			*all_alive;
}	t_fork;

typedef struct s_data
{
	pthread_t				tid_die;
	pthread_t				tid_ate;
	int						num_philo;
	int						n_time_eat;
	int						n_time_die;
	int						n_time_sleep;
	int						n_num_philo_eat;
	unsigned long long		time;
	t_fork					*sems;
	t_philo					*first_philo;
}					t_data;

typedef struct s_philo_info
{
	t_data	*data;
	t_philo	*philo;
}	t_philo_info;

int						valid(int c, const char**v);
int						data_valid(t_data *data);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
t_philo					*new_philo(void);
void					ft_put_err(char *str);
void					ft_lstadd_back(t_philo **lst, t_philo *newl);
void					ft_philoclear(t_philo **stack);
t_philo_info			*get_philo(t_data *data, t_philo *philo);
void					born_philo(t_data *data, t_philo *philo);
unsigned long long		get_time(void);
unsigned long long		time_now(t_data *data);
void					*ate_monitoring(void *tmp);
void					*die_monitoring(void *tmp);
void					kill_philos(t_data *data);
int						philo_detach(t_data *data);
t_fork					*new_fork(int forks, int need_ate);
void					forks_clean(t_fork *sem);
void					ft_usleep(unsigned long long time);

#endif
