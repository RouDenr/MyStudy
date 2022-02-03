/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:22:16 by decordel          #+#    #+#             */
/*   Updated: 2022/02/03 22:44:57 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	forks_free(t_data *data, t_philo *philo)
{
	if (philo->next != NULL)
		return (philo->fork_free && philo->next->fork_free);
	else if (data->first_philo != philo)
		return (philo->fork_free && data->first_philo->fork_free);
	return (0);
}

void	philo_eat(t_data *data, t_philo *philo, t_philo *philo_r)
{
	printf("%d %d has taken a fork\n", time_now(data), philo->n_p);
	philo->fork_free = 0;
	philo_r->fork_free = 0;
	printf("%d %d is eating\n", time_now(data), philo->n_p);
	pthread_mutex_unlock(&(data->mutex));
	usleep(data->n_time_eat * 1000);
	philo->count_eat++;
	philo->fork_free = 1;
	philo_r->fork_free = 1;
	printf("%d %d is sleeping\n", time_now(data), philo->n_p);
	philo->time_die = time_now(data) + data->n_time_sleep;
	usleep(data->n_time_sleep * 1000);
	printf("%d %d is thinking\n", time_now(data), philo->n_p);
}

int	take_forks(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->mutex));
	if (forks_free(data, philo))
	{
		if (philo->next)
			philo_eat(data, philo, philo->next);
		else
			philo_eat(data, philo, data->first_philo);
	}
	else
		pthread_mutex_unlock(&(data->mutex));
	return (0);
}

void	*born_philo(void *tmp)
{
	t_data	*data;
	t_philo	*philo;

	data = ((t_philo_info *)tmp)->data;
	philo = ((t_philo_info *)tmp)->philo;
	free(tmp);
	printf("%d %d is thinking\n", time_now(data), philo->n_p);
	philo->time_die = time_now(data);
	while (data->n_num_philo_eat)
	{
		if (forks_free(data, philo))
			take_forks(data, philo);
	}
	return (tmp);
}
