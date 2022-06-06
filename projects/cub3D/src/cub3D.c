/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:51:44 by decordel          #+#    #+#             */
/*   Updated: 2022/06/06 18:25:14 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	cub(char **arg)
{
	if (arg)
		return ;
	return ;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (1);
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, 500, 500, "cub3d");
	mlx_hook(mlx.win, 17, 0L, (int (*)(int))exit, &mlx);
	ft_putendl_fd(*argv, 1);
	mlx_loop(mlx.init);
	return (0);
}
