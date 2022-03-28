/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:12:14 by decordel          #+#    #+#             */
/*   Updated: 2021/12/14 00:06:32 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_space(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->data[j])
	{
		i = 0;
		while (map->data[j][i])
		{
			mlx_put_image_to_window(mlx->init, mlx->win, map->img_space,
				i * SPRITE_W, j * SPRITE_H);
			i++;
		}
		j++;
	}
}

void	*chose_sprites(t_map *map, char sprite)
{
	if (sprite == '0')
		return (map->img_space);
	if (sprite == 'P')
		return (map->img_player);
	if (sprite == 'E')
		return (map->img_exit);
	if (sprite == '1')
		return (map->img_wall);
	if (sprite == 'C')
		return (map->img_coll);
	if (sprite == 'X')
		return (map->img_en);
	return (NULL);
}

void	draw_map(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;
	void	*img;

	j = 0;
	while (map->data[j])
	{
		i = 0;
		while (map->data[j][i])
		{
			img = chose_sprites(map, map->data[j][i]);
			mlx_put_image_to_window(mlx->init, mlx->win,
				img, i * SPRITE_W, j * SPRITE_H);
			i++;
		}
		j++;
	}
}

void	draw_num(t_mlx *mlx, void *num[], int n)
{
	int	x;
	int	y;

	x = mlx->map.w - 25;
	y = 0;
	mlx_put_image_to_window(mlx->init, mlx->win,
		num[n % 10], x, y);
	x -= 25;
	n /= 10;
	while (n != 0)
	{
		mlx_put_image_to_window(mlx->init, mlx->win,
			num[n % 10], x, y);
		x -= 25;
		n /= 10;
	}
}
