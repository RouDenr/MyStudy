/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:26:23 by decordel          #+#    #+#             */
/*   Updated: 2022/06/08 19:05:28 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_valid_items(char map)
{
	if (map == '0' || map == '1' || map == '\n')
		return (1);
	if (map == 'W' || map == 'E' || map == 'S')
		return (1);
	if (map == 'N')
		return (1);
	return (0);
}

int	check_invalid_items(char *map)
{
	while (*map)
	{
		if (!is_valid_items(*map))
			ft_put_err("на карте посторонний символ");
		map++;
	}
	return (1);
}

void	find_pl(t_player *player, char **data)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	find = 0;
	while (data[++i])
	{
		j = 0;
		while (data[i][++j])
		{
			if (data[i][j] == 'W' || data[i][j] == 'E'
				|| data[i][j] == 'S' || data[i][j] == 'N')
			{
				player->x = j;
				player->y = i;
				player->start_dir = data[i][j];
				if (find)
					ft_put_err("больше одного игрока на карте");
				find = 1;
			}
		}
	}
}

int	check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j][i])
		if (map[j][i++] != '1')
			ft_put_err("Карта должна быть окружена стенами");
	i--;
	while (map[j])
		if (map[j++][i] != '1')
			ft_put_err("Карта должна быть окружена стенами");
	j--;
	while (i--)
		if (map[j][i] != '1')
			ft_put_err("Карта должна быть окружена стенами");
	i++;
	while (j--)
		if (map[j][i] != '1')
			ft_put_err("Карта должна быть окружена стенами");
	return (1);
}
