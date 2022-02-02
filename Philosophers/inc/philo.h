/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:20:37 by decordel          #+#    #+#             */
/*   Updated: 2022/02/03 02:28:34 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <libc.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		tid;
	int				n_p;
	int				fork_free;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	struct s_philo	*next;

}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	mutex;
	int				num_philo;
	int				n_time_eat;
	int				n_time_die;
	int				n_time_sleep;
	int				n_num_philo_eat;
	t_philo			*first_philo;
}					t_data;

typedef struct s_philo_info
{
	t_data	*data;
	t_philo	*philo;
}	t_philo_info;

void			print_philos(t_data *data);
int				valid(int c, const char**v);
int				ft_atoi(const char *str);
t_philo			*new_philo(void);
void			ft_lstadd_back(t_philo **lst, t_philo *newl);
void			ft_philoclear(t_philo **stack);
t_philo_info	*get_philo(t_data *data, t_philo *philo);
void			*born_philo(void *tmp);

#endif
