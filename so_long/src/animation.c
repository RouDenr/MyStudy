/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:33:17 by decordel          #+#    #+#             */
/*   Updated: 2021/12/11 22:04:43 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	player_animation(t_map *map, t_mlx *mlx, int i)
{
	int			x;
	int			y;

	if (map->p_right)
	{
		if (i > 10 == 0)
			map->img_player = mlx_xpm_file_to_image(mlx->init,
					"img/dino_r_1.xpm", &x, &y);
		else
			map->img_player = mlx_xpm_file_to_image(mlx->init,
					"img/dino_r_2.xpm", &x, &y);
	}
	else
		if (i > 10 == 0)
			map->img_player = mlx_xpm_file_to_image(mlx->init,
					"img/dino_l_1.xpm", &x, &y);
	else
			map->img_player = mlx_xpm_file_to_image(mlx->init,
				"img/dino_l_2.xpm", &x, &y);
}

static void	collectible_animation(t_map *map, t_mlx *mlx, int i)
{
	int			x;
	int			y;

	if (i > 10)
		map->img_coll = mlx_xpm_file_to_image(mlx->init,
				"img/item_gr_1.xpm", &x, &y);
	else
		map->img_coll = mlx_xpm_file_to_image(mlx->init,
				"img/item_gr_2.xpm", &x, &y);
}

static void	enemy_animation(t_map *map, t_mlx *mlx, int i)
{
	int			x;
	int			y;

	if (i > 10)
		map->img_en = mlx_xpm_file_to_image(mlx->init,
				"img/enemy.xpm", &x, &y);
	else
		map->img_en = mlx_xpm_file_to_image(mlx->init,
				"img/enemy_1.xpm", &x, &y);
}

void	get_animation(t_map *map, t_mlx *mlx)
{
	static int	i;

	player_animation(map, mlx, i);
	collectible_animation(map, mlx, i);
	enemy_animation(map, mlx, i);
	i++;
	if (i > 20)
		i = 0;
}
