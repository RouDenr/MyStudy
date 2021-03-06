/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:22:16 by decordel          #+#    #+#             */
/*   Updated: 2022/03/04 19:43:31 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	put_mess(int n_philo, char *mess, t_data *data)
{
	if (data->n_num_philo_eat)
		printf("%llu %d%s", time_now(data), n_philo, mess);
}

void	philo_eat(t_data *data, t_philo *philo)
{
	put_mess(philo->n_p, " is eating\n", data);
	philo->last_eat = time_now(data);
	ft_usleep(data->n_time_eat);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(&(philo->fork));
	philo->count_eat++;
	put_mess(philo->n_p, " is sleeping\n", data);
	ft_usleep(data->n_time_sleep);
	put_mess(philo->n_p, " is thinking\n", data);
}

int	take_forks(t_data *data, t_philo *philo)
{
	// pthread_mutex_lock(&(data->mutex));
	pthread_mutex_lock(&(philo->fork));
	put_mess(philo->n_p, " has taken a fork\n", data);
	pthread_mutex_lock(philo->fork_r);
	put_mess(philo->n_p, " has taken a fork\n", data);
	// pthread_mutex_unlock(&(data->mutex));
	philo_eat(data, philo);
	return (0);
}

void	*born_philo(void *tmp)
{
	t_data	*data;
	t_philo	*philo;

	data = ((t_philo_info *)tmp)->data;
	philo = ((t_philo_info *)tmp)->philo;
	free(tmp);
	put_mess(philo->n_p, " is thinking\n", data);
	if (philo->next)
		philo->fork_r = &(philo->next->fork);
	else
		philo->fork_r = &(data->first_philo->fork);
	philo->last_eat = time_now(data);
	while (data->n_num_philo_eat)
		take_forks(data, philo);
	return (tmp);
}
