/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:20:37 by decordel          #+#    #+#             */
/*   Updated: 2022/02/24 18:29:45 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define RED_ERR "\033[1;31m"
# define DEF "\033[0;0m"
# include <libc.h>
# include <pthread.h>

typedef struct s_philo
{
	int				n_p;
	pid_t			pid;
	int				fork_free;
	int				count_eat;
	int				last_eat;
	struct s_philo	*next;

}					t_philo;

typedef struct s_data
{
	pthread_mutex_t			mutex;
	pthread_t				tid;
	int						num_philo;
	int						n_time_eat;
	int						n_time_die;
	int						n_time_sleep;
	int						n_num_philo_eat;
	unsigned long long		time;
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
t_philo					*new_philo(void);
void					ft_put_err(char *str);
void					ft_lstadd_back(t_philo **lst, t_philo *newl);
void					ft_philoclear(t_philo **stack);
t_philo_info			*get_philo(t_data *data, t_philo *philo);
void					born_philo(t_data *data, t_philo *philo);
unsigned long long		get_time(void);
int						time_now(t_data *data);
void					*monitoring(void *tmp);
int						philo_detach(t_data *data);

#endif
