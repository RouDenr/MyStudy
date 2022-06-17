/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:51:44 by decordel          #+#    #+#             */
/*   Updated: 2022/06/12 17:41:56 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	do_next_frame(t_mlx *mlx)
{
	// int i = 0;
	// int j;

	// while (i < 500)
	// {
	// 	j = 0;
	// 	while (j < 500)
	// 	{
	// 		ft_pixel_put(&mlx->screen, j, i, 0x00FF0000);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// ft_img_put_screen(&mlx->screen, &mlx->wall, 0, 0);

	// mlx_put_image_to_window(mlx->init, mlx->win, mlx->screen.img, 0, 0);

	// mlx_destroy_image(mlx->init, mlx->screen.img);

	return (mlx->player.dir_x);
}

int	exit_hook(void)
{
	exit(0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	// if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	// 	pl_move(mlx, &mlx->map, mlx->map.data, keycode);
	// if (keycode == 126 || keycode == 123 || keycode == 125 || keycode == 124)
	// 	pl_move(mlx, &mlx->map, mlx->map.data, keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		x;
	int		y;

	if (argc != 2)
		return (ft_ret_err("./cub3D map.cub", 1));
	init_map(argv[1], &mlx);
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, 1920, 1080, "cub3d");


	mlx.player.dir_x = 0;
	mlx.player.dir_y = 1;
	mlx.player.x = 18;
	mlx.player.y = 3;
	mlx.player.plane_x = 0;
	mlx.player.plane_y = 0.66;


	mlx.wall.img = mlx_xpm_file_to_image(mlx.init, "texture/w_wall.xpm", &x, &y);
	printf("x %d; y %d;\n", x, y);
	mlx.wall.w = x;
	mlx.wall.h = y;
	mlx.wall.addr = mlx_get_data_addr(mlx.wall.img, &mlx.wall.bits_per_pixel, &mlx.wall.line_length, &mlx.wall.endian);
	printf("bits %d; line %d; end %d;\n", mlx.wall.bits_per_pixel, mlx.wall.line_length, mlx.wall.endian);
	// mlx.screen = mlx.wall;

	mlx.screen.img = mlx_new_image(mlx.init, 500, 500);
	mlx.screen.addr = mlx_get_data_addr(mlx.screen.img, &mlx.screen.bits_per_pixel,
		&mlx.screen.line_length, &mlx.screen.endian);


	mlx_hook(mlx.win, 17, 0L, exit_hook, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, key_hook, &mlx);
	mlx_loop_hook(mlx.init, do_next_frame, &mlx);
	mlx_loop(mlx.init);
	return (0);
}

