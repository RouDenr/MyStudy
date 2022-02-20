/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:46:26 by decordel          #+#    #+#             */
/*   Updated: 2022/02/20 17:09:38 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_philos(t_data *data)
{
	t_philo	*tmp;

	tmp = data->first_philo;
	printf("\n\033[1;32m[---------------|\n");
	printf("|  Philosophers\t|\n");
	printf("|---------------|\n");
	printf("| \033[1;34mfork\033[1;32m\t| \033[1;31mdie\033[1;32m\t|\n");
	printf("|-------|-------|\n");
	while (tmp)
	{
		printf("|\033[1;34m%d\033[1;32m\t|\033[1;31m%d\033[1;32m\t|\n",
			tmp->fork_free, tmp->last_eat);
		if (tmp)
			tmp = tmp->next;
	}
	printf("----------------]\033[0m\n\n");
	read(0, NULL, 1);
}
