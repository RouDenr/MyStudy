/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:22:16 by decordel          #+#    #+#             */
/*   Updated: 2022/02/03 02:35:01 by decordel         ###   ########.fr       */
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

int	philo_eat(t_data *data, t_philo *philo, t_philo *philo_r)
{
	printf("%d philo eat...\n", philo->n_p);
	philo->fork_free = 0;
	philo_r->fork_free = 0;
	// print_philos(data);
	pthread_mutex_unlock(&(data->mutex));
	usleep(data->n_time_eat * 1000);
	printf("%d philo sleep...\n", philo->n_p);
	usleep(data->n_time_sleep * 1000);
	printf("%d philo think...\n", philo->n_p);
	philo->fork_free = 1;
	philo_r->fork_free = 1;
	return (1);
}

int	take_forks(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->mutex));
	if (forks_free(data, philo))
	{
		printf("philo eat...\n");
		if (philo->next)
			philo_eat(data, philo, philo->next);
		else
			philo_eat(data, philo, data->first_philo);
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
	printf("%d philo think...\n", philo->n_p);
	while (1)
	{
		if (forks_free(data, philo))
			take_forks(data, philo);
	}

	return (tmp);
}
