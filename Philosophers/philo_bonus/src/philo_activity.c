/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:22:16 by decordel          #+#    #+#             */
/*   Updated: 2022/03/02 15:51:55 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	put_mess(int n_philo, char *mess, t_data *data)
{
	if (data->n_num_philo_eat)
		printf("%llu %d %s", time_now(data), n_philo, mess);
}

void	*die_this_monitoring(void *tmp)
{
	t_data	*data;
	t_philo	*philo;

	data = ((t_philo_info *)tmp)->data;
	philo = ((t_philo_info *)tmp)->philo;
	while (time_now(data) - philo->last_eat
		<= (unsigned long long) data->n_time_die)
		ft_usleep(10);
	printf("\033[38;05;196m%llu %d IS DEAD\033[0m\n",
		time_now(data), philo->n_p);
	data->n_num_philo_eat = 0;
	sem_post(data->sems->all_alive);
	exit(0);
}

void	philo_eat(t_data *data, t_philo *philo)
{
	put_mess(philo->n_p, "is eating\n", data);
	philo->last_eat = time_now(data);
	ft_usleep(data->n_time_eat);
	sem_post(data->sems->forks);
	sem_post(data->sems->forks);
	if (++(philo->count_eat) == data->n_num_philo_eat)
		sem_post(data->sems->all_ate);
	put_mess(philo->n_p, "is sleeping\n", data);
	ft_usleep(data->n_time_sleep);
	put_mess(philo->n_p, "is thinking\n", data);
}

int	take_forks(t_data *data, t_philo *philo)
{
	sem_wait(data->sems->forks);
	put_mess(philo->n_p, "has taken a fork\n", data);
	sem_wait(data->sems->forks);
	put_mess(philo->n_p, "has taken a fork\n", data);
	philo_eat(data, philo);
	return (0);
}

void	born_philo(t_data *data, t_philo *philo)
{
	put_mess(philo->n_p, "is thinking\n", data);
	philo->last_eat = time_now(data);
	if (pthread_create(&(philo->tid), NULL, &die_this_monitoring,
			get_philo(data, philo)) != 0)
	{
		printf("Pthread create error");
		exit(1);
	}
	while (1)
		take_forks(data, philo);
	exit(0);
}
