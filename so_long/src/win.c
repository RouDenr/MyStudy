/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:47:36 by decordel          #+#    #+#             */
/*   Updated: 2021/12/14 00:10:11 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	do_next_frame(t_mlx *mlx)
{
	draw_space(mlx, &mlx->map);
	draw_map(mlx, &mlx->map);
	return (1);
}

void static	num_init(t_mlx *mlx)
{
	int		x;
	int		y;
	int		i;
	char	path[14];

	i = 0;
	ft_strlcpy(path, "img/num/0.xpm", 14);
	while (i < 10)
	{
		path[8] = i + '0';
		mlx->map.img_num[i] = mlx_xpm_file_to_image(mlx->init, path,
				&x, &y);
		i++;
	}
}

void	image_init(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->map.img_space = mlx_xpm_file_to_image(mlx->init, SPACE_PATH,
			&x, &y);
	mlx->map.img_coll = mlx_xpm_file_to_image(mlx->init, COLL_PATH,
			&x, &y);
	mlx->map.img_exit = mlx_xpm_file_to_image(mlx->init, EX_PATH,
			&x, &y);
	mlx->map.img_player = mlx_xpm_file_to_image(mlx->init, PL_PATH,
			&x, &y);
	mlx->map.img_wall = mlx_xpm_file_to_image(mlx->init, WALL_PATH,
			&x, &y);
	mlx->map.img_en = mlx_xpm_file_to_image(mlx->init, ENEMY_PATH,
			&x, &y);
	mlx->map.p_right = 1;
	num_init(mlx);
}

static void	find_pl(t_map *map, char **data)
{
	int	i;
	int	j;

	i = 0;
	while (data[++i])
	{
		j = 0;
		while (data[i][++j])
		{
			if (data[i][j] == 'P')
			{
				map->p_x = j;
				map->p_y = i;
				return ;
			}
		}
	}
}

void	win_init(t_mlx *mlx)
{
	get_size_map(&mlx->map);
	mlx->init = mlx_init();
	mlx->steps = 0;
	mlx->win = mlx_new_window(mlx->init, mlx->map.w, mlx->map.h, "so_long");
	find_pl(&mlx->map, mlx->map.data);
	mlx_hook(mlx->win, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0L, (int (*)(int))exit, &mlx);
	image_init(mlx);
	mlx_loop_hook(mlx->init, do_next_frame, mlx);
	mlx_loop(mlx->init);
}
