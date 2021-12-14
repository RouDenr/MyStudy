/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:30:01 by decordel          #+#    #+#             */
/*   Updated: 2021/12/14 00:37:13 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	pl_step(int x, int y, t_map *map, t_mlx *mlx)
{
	map->data[map->p_y][map->p_x] = '0';
	map->data[y][x] = 'P';
	if (y > map->p_y)
		mlx_put_image_to_window(mlx->init, mlx->win,
			map->img_player, x * SPRITE_W, y * SPRITE_H - 50);
	if (y < map->p_y)
		mlx_put_image_to_window(mlx->init, mlx->win,
			map->img_player, x * SPRITE_W, y * SPRITE_H + 50);
	if (x > map->p_x)
		mlx_put_image_to_window(mlx->init, mlx->win,
			map->img_player, x * SPRITE_W - 50, y * SPRITE_H);
	if (x < map->p_x)
		mlx_put_image_to_window(mlx->init, mlx->win,
			map->img_player, x * SPRITE_W + 50, y * SPRITE_H);
	map->p_x = x;
	map->p_y = y;
	mlx->steps++;
	check_map_win(mlx->map.data, mlx);
}

static int	check_win(char **data, t_mlx *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (data[++j])
	{
		i = 0;
		while (data[j][++i])
			if (data[j][i] == 'C')
				return (0);
	}
	mlx_destroy_window(mlx->init, mlx->win);
	exit(0);
}

static int	is_spase(char c, t_mlx *mlx)
{
	if (c == '1')
		return (0);
	if (c == 'X')
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	if (c == 'E')
		return (check_win(mlx->map.data, mlx));
	return (1);
}

static void	pl_move(t_mlx *mlx, t_map *map, char **data, int key)
{
	int	x;
	int	y;

	x = map->p_x;
	y = map->p_y;
	if (key == 13 || key == 126)
		if (is_spase(data[y - 1][x], mlx))
			pl_step(x, y - 1, map, mlx);
	if (key == 1 || key == 125)
		if (is_spase(data[y + 1][x], mlx))
			pl_step(x, y + 1, map, mlx);
	if (key == 0 || key == 123)
	{
		if (is_spase(data[y][x - 1], mlx))
			pl_step(x - 1, y, map, mlx);
		map->p_right = 0;
	}
	if (key == 2 || key == 124)
	{
		if (is_spase(data[y][x + 1], mlx))
			pl_step(x + 1, y, map, mlx);
		map->p_right = 1;
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		pl_move(mlx, &mlx->map, mlx->map.data, keycode);
	if (keycode == 126 || keycode == 123 || keycode == 125 || keycode == 124)
		pl_move(mlx, &mlx->map, mlx->map.data, keycode);
	return (0);
}
