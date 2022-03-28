/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:27:42 by decordel          #+#    #+#             */
/*   Updated: 2022/03/04 23:49:40 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	data_init(t_data *data, const char **argv)
{
	int	i;

	data->num_philo = ft_atoi(argv[1]);
	data->n_time_die = ft_atoi(argv[2]);
	data->n_time_eat = ft_atoi(argv[3]);
	data->n_time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_num_philo_eat = ft_atoi(argv[5]);
	else
		data->n_num_philo_eat = -5;
	if (!data_valid(data))
		ft_put_err("Not valid args");
	data->time = get_time();
	data->first_philo = NULL;
	data->sems = new_fork(data->num_philo, data->n_time_eat);
	i = 0;
	while (i++ < data->num_philo)
		ft_lstadd_back(&(data->first_philo), new_philo());
}

int	philo_init(t_data *data)
{
	t_philo	*philo;

	philo = data->first_philo;
	while (philo)
	{
		philo->pid = fork();
		if (!philo->pid)
			born_philo(data, philo);
		else if (philo->pid < 0)
			ft_put_err("Fork err");
		philo = philo->next;
		usleep(100);
	}
	return (1);
}

void	monitoring_init(t_data *data)
{
	if (pthread_create(&(data->tid_ate), NULL, &ate_monitoring,
			data) != 0)
		printf("Pthread create error");
	if (pthread_create(&(data->tid_die), NULL, &die_monitoring,
			data) != 0)
		printf("Pthread create error");
}

int	philo_join(t_data *data)
{
	if (pthread_join(data->tid_ate, NULL) != 0)
	{
		printf("Pthread join error");
		return (0);
	}
	if (pthread_join(data->tid_die, NULL) != 0)
	{
		printf("Pthread join error");
		return (0);
	}
	return (1);
}

int	main(int argc, const char **argv)
{
	t_data	data;

	if (!valid(argc, argv))
		return (1);
	data_init(&data, argv);
	if (!philo_init(&data))
		return (2);
	monitoring_init(&data);
	if (!philo_join(&data))
		return (3);
	return (0);
}
