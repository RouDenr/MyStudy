/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:22:16 by decordel          #+#    #+#             */
/*   Updated: 2022/02/20 21:21:54 by decordel         ###   ########.fr       */
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
	philo->last_eat = time_now(data);
	printf("%d %d is eating\n", philo->last_eat, philo->n_p);
	usleep(data->n_time_eat * 1000);
	philo->count_eat++;
	philo->fork_free = 1;
	philo_r->fork_free = 1;
	printf("%d %d is sleeping\n", time_now(data), philo->n_p);
	usleep(data->n_time_sleep * 1000);
	printf("%d %d is thinking\n", time_now(data), philo->n_p);
}

// int	take_forks(t_data *data, t_philo *philo, t_philo *philo_r)
// {
// 	pthread_mutex_lock(&(philo->mutex));
// 	printf("%d %d has taken a fork\n", time_now(data), philo->n_p, philo->n_p);
// 	pthread_mutex_lock(&(philo_r->mutex));
// 	printf("%d %d has taken a fork\n", time_now(data), philo->n_p, philo_r->n_p);
// 	philo_eat(data, philo, philo_r);
// 	return (0);
// }

int	take_forks(t_data *data, t_philo *philo, t_philo *philo_r)
{
	// pthread_mutex_lock(&(data->mutex));
	// printf("%d %d has taken a fork %d\n", time_now(data), philo->n_p, philo->n_p);
	philo->fork_free = 0;
	if (philo_r->fork_free)
	{
		pthread_mutex_lock(&(philo_r->mutex));
		philo_r->fork_free = 0;
		// pthread_mutex_unlock(&(data->mutex));
		pthread_mutex_unlock(&(philo->mutex));
		pthread_mutex_unlock(&(philo_r->mutex));
		printf("%d %d has taken a fork\n", time_now(data), philo->n_p);
		philo_eat(data, philo, philo_r);
	}
	else
	{
		philo->fork_free = 1;
		pthread_mutex_unlock(&(philo->mutex));
		// pthread_mutex_unlock(&(data->mutex));
	}
	return (0);
}

int	try_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex));
	if (philo->fork_free)
	{
		if (philo->next)
			take_forks(data, philo, philo->next);
		else
			take_forks(data, philo, data->first_philo);
		return (1);
	}
	else
		pthread_mutex_unlock(&(philo->mutex));
	return (0);
}

void	*born_philo(void *tmp)
{
	t_data	*data;
	t_philo	*philo;

	data = ((t_philo_info *)tmp)->data;
	philo = ((t_philo_info *)tmp)->philo;
	free(tmp);
	philo->last_eat = time_now(data);
	printf("%d %d is thinking\n", time_now(data), philo->n_p);
	while (data->n_num_philo_eat)
		try_eat(data, philo);
	return (tmp);
}
