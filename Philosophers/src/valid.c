/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:25:07 by decordel          #+#    #+#             */
/*   Updated: 2022/01/28 16:43:40 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	valid(int c, const char **v)
{
	int	i;
	int	j;

	if (c < 5 || c > 6)
	{
		printf("./philo number_of_philosophers time_to_die time_to_eat\
 time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (0);
	}
	i = 1;
	while (i < c)
	{
		j = 0;
		while (v[i][j])
		{
			if (!ft_isdigit(v[i][j]))
			{
				printf("arg %d not valid\n", i);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
