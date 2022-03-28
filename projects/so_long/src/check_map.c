/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:26:23 by decordel          #+#    #+#             */
/*   Updated: 2021/12/11 21:40:31 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_rectangle(char *map)
{
	int	len;
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	len = 0;
	while (map[i] != '\n' && map[i])
	{
		len++;
		i++;
	}
	while (map[i++])
	{
		if (map[i] == '\n')
		{
			if (temp != len)
				put_error("карта должна быть прямоугольной формы");
			temp = 0;
			continue ;
		}
		temp++;
	}
	return (1);
}

static int	is_valid_items(char map)
{
	if (map == 'P' || map == 'E' || map == 'C')
		return (1);
	if (map == '0' || map == '1' || map == '\n')
		return (1);
	if (map == 'X')
		return (1);
	return (0);
}

int	check_invalid_items(char *map)
{
	while (*map)
	{
		if (!is_valid_items(*map))
			put_error("на карте посторонний символ");
		map++;
	}
	return (1);
}

int	check_items(char *map)
{
	char	*p;

	if (!ft_strchr(map, 'C'))
		put_error("нет коллекционных предметов на карте");
	if (!ft_strchr(map, 'E'))
		put_error("нет выхода с карты");
	p = ft_strchr(map, 'P');
	if (!p++)
		put_error("нет игрока на карте");
	if (ft_strchr(p, 'P'))
		put_error("больше одного игрока на карте");
	return (1);
}

int	check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j][i])
		if (map[j][i++] != '1')
			put_error("Карта должна быть окружена стенами");
	i--;
	while (map[j])
		if (map[j++][i] != '1')
			put_error("Карта должна быть окружена стенами");
	j--;
	while (i--)
		if (map[j][i] != '1')
			put_error("Карта должна быть окружена стенами");
	i++;
	while (j--)
		if (map[j][i] != '1')
			put_error("Карта должна быть окружена стенами");
	return (1);
}
