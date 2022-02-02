/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:22:16 by decordel          #+#    #+#             */
/*   Updated: 2022/01/29 15:02:26 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	forks_free(t_data *data, t_philo *philo)
{
	if (philo->next)
		return (philo->fork_free && philo->next->fork_free);
	else
		return (philo->fork_free && data->first_philo->fork_free);
}

int	take_forks(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->mutex));
	if (forks_free(data, philo))
	{
		printf("philo eat...\n");
		if (philo->next)
		{
			philo->fork_free = 0;
			philo->next->fork_free = 0;
			print_philos(data);
			pthread_mutex_unlock(&(data->mutex));
			usleep(data->n_time_eat * 1000);
			philo->fork_free = 1;
			philo->next->fork_free = 1;
		}
		else
		{
			philo->fork_free = 0;
			data->first_philo->fork_free = 0;
			print_philos(data);
			pthread_mutex_unlock(&(data->mutex));
			usleep(data->n_time_eat * 1000);
			philo->fork_free = 1;
			data->first_philo->fork_free = 1;
		}
	}
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
	// printf("Hello philo! %p\n", philo);
	while (1)
	{
		if (forks_free(data, philo))
			take_forks(data, philo);
	}

	return (tmp);
}
