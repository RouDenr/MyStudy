/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:47:36 by decordel          #+#    #+#             */
/*   Updated: 2022/06/06 21:31:31 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	do_next_frame(t_mlx *mlx)
{
	draw_space(mlx, &mlx->map);
	get_animation(&mlx->map, mlx);
	enemy_goes(mlx->map.data);
	draw_map(mlx, &mlx->map);
	draw_num(mlx, mlx->map.img_num, mlx->steps);
	return (1);
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
