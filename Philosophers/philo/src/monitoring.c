/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:08:04 by decordel          #+#    #+#             */
/*   Updated: 2022/02/23 22:58:09 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	all_philo_ate(t_data *data)
{
	t_philo	*philo;

	philo = data->first_philo;
	while (philo)
	{
		if (philo->count_eat < data->n_num_philo_eat || data->n_num_philo_eat < 0)
			return (0);
		philo = philo->next;
	}
	data->n_num_philo_eat = 0;
	philo_detach(data);
	printf("\033[38;05;46m%d ALL ATE\033[0m\n", time_now(data));
	return (1);
}

int	all_philo_alive(t_data *data)
{
	t_philo	*philo;

	philo = data->first_philo;
	while (philo)
	{
		if (time_now(data) - philo->last_eat > data->n_time_die)
		{
			data->n_num_philo_eat = 0;
			philo_detach(data);
			printf("\033[38;05;196m%d %d IS DEAD\033[0m\n",
				time_now(data), philo->n_p);
			return (0);
		}
		philo = philo->next;
	}
	return (1);
}

int	philo_detach(t_data *data)
{
	t_philo	*philo;

	philo = data->first_philo;
	while (philo)
	{
		if (pthread_detach(philo->tid) != 0)
		{
			printf("Pthread detach error");
			return (0);
		}
		philo = philo->next;
	}
	return (1);
}

void	*monitoring(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	while (!all_philo_ate(data) && all_philo_alive(data))
		;
	return (data);
}
