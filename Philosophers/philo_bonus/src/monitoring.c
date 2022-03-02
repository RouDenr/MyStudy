/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:08:04 by decordel          #+#    #+#             */
/*   Updated: 2022/03/02 15:50:45 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	kill_philos(t_data *data)
{
	t_philo	*philo;

	philo = data->first_philo;
	while (philo)
	{
		kill(philo->pid, SIGKILL);
		philo = philo->next;
	}
}

void	*die_monitoring(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	sem_wait(data->sems->all_alive);
	pthread_detach(data->tid_ate);
	kill_philos(data);
	forks_clean(data->sems);
	ft_philoclear(&(data->first_philo));
	exit(0);
}

void	*ate_monitoring(void *tmp)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)tmp;
	philo = data->first_philo;
	while (philo)
	{
		sem_wait(data->sems->all_ate);
		philo = philo->next;
	}
	printf("\033[38;05;46m%llu ALL ATE\033[0m\n",
		time_now(data));
	pthread_detach(data->tid_die);
	kill_philos(data);
	forks_clean(data->sems);
	ft_philoclear(&(data->first_philo));
	exit(0);
}
