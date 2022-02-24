/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:26:34 by decordel          #+#    #+#             */
/*   Updated: 2022/02/24 18:28:43 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long long) 1000) + (time.tv_usec / 1000));
}

unsigned long long	time_now(t_data *data)
{
	return (get_time() - data->time);
}

void	ft_usleep(unsigned long long time)
{
	unsigned long long	start;

	start = get_time();
	while (time > get_time() - start)
		usleep(100);
}

// int main(int argc, char const *argv[])
// {
// 	ft_usleep(10000);
// 	return 0;
// }
