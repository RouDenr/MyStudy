/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:27:42 by decordel          #+#    #+#             */
/*   Updated: 2022/02/24 18:09:55 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	data_init(t_data *data, const char **argv)
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
		return (0);
	data->time = get_time();
	data->first_philo = NULL;
	i = 0;
	while (i++ < data->num_philo)
		ft_lstadd_back(&(data->first_philo), new_philo());
	return (1);
}

int	philo_init(t_data *data)
{
	t_philo	*philo;

	philo = data->first_philo;
	while (philo)
	{
		usleep(100);
		if (pthread_create(&(philo->tid), NULL, &born_philo,
				get_philo(data, philo)) != 0)
		{
			printf("Pthread create error\n");
			return (0);
		}
		philo = philo->next;
	}
	if (pthread_create(&(data->tid), NULL, &monitoring,
			data) != 0)
	{
		printf("Pthread create error\n");
		return (0);
	}
	return (1);
}

int	philo_join(t_data *data)
{
	if (pthread_join(data->tid, NULL) != 0)
	{
		return (0);
	}
	return (1);
}

int	main(int argc, const char **argv)
{
	t_data	data;

	if (!valid(argc, argv))
		return (1);
	if (!data_init(&data, argv))
		return (2);
	if (!philo_init(&data))
		return (3);
	if (!philo_join(&data))
		return (4);
	ft_philoclear(&(data.first_philo));
	return (0);
}
