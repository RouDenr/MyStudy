/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:22:16 by decordel          #+#    #+#             */
/*   Updated: 2022/02/24 01:11:41 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	put_mess(int n_philo, char *mess, t_data *data)
{
	if (data->n_num_philo_eat)
		printf("%d %d%s", time_now(data), n_philo, mess);
}

void	philo_eat(t_data *data, t_philo *philo)
{
	put_mess(philo->n_p, " is eating\n", data);
	philo->last_eat = time_now(data);
	usleep(data->n_time_eat * 1000);
	philo->count_eat++;
	put_mess(philo->n_p, " is sleeping\n", data);
	usleep(data->n_time_sleep * 1000);
	put_mess(philo->n_p, " is thinking\n", data);
}

int	take_forks(t_data *data, t_philo *philo)
{
	put_mess(philo->n_p, " has taken a fork\n", data);
	put_mess(philo->n_p, " has taken a fork\n", data);
	philo_eat(data, philo);
	return (0);
}

void	born_philo(t_data *data, t_philo *philo)
{
	put_mess(philo->n_p, " is thinking\n", data);
	philo->last_eat = time_now(data);
	while (data->n_num_philo_eat)
		take_forks(data, philo);
	exit(0);
}
