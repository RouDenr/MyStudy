/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:08:04 by decordel          #+#    #+#             */
/*   Updated: 2022/02/03 22:40:46 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	all_philo_ate(t_data *data)
{
	t_philo	*philo;

	philo = data->first_philo;
	while (philo)
	{
		if (philo->count_eat < data->n_num_philo_eat)
			return (0);
		philo = philo->next;
	}
	printf("\033[38;05;46mALL ATE\n");
	return (1);
}

int	all_philo_alive(t_data *data)
{
	t_philo	*philo;

	philo = data->first_philo;
	while (philo)
	{
		if (time_now(data) - philo->time_die > data->n_time_die)
		{
			printf("\033[38;05;196m%d %d IS DEAD\n", time_now(data), philo->n_p);
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
	while (!all_philo_ate(data) && all_philo_alive(data));

	return (data);
}
