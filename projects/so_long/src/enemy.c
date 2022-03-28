/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:29:09 by decordel          #+#    #+#             */
/*   Updated: 2021/12/14 00:06:47 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	enemy_step(char *en)
{
	static int	n = 1;

	if (en[n] == 'P')
	{
		en[0] = '0';
		en[n] = 'X';
		exit(0);
	}
	if (en[n] != '0')
		n = -n;
	if (en[n] == '0')
	{
		en[0] = '0';
		en[n] = 'X';
	}
}

void	enemy_goes(char **map)
{
	static int	n;
	int			i;

	while (*map && n == 15)
	{
		i = 0;
		while ((*map)[i])
		{
			if (map[0][i] == 'X')
			{
				enemy_step(&map[0][i]);
				i++;
			}
			i++;
		}
		map++;
	}
	if (++n > 30)
		n = 0;
}
