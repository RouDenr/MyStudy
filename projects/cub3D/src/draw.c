/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:07:56 by decordel          #+#    #+#             */
/*   Updated: 2022/06/12 17:52:46 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_img_put_screen(t_img *screen, t_img *img, int x, int y)
{
	char	*dst;
	char	*dst_screen;
	int		size = 100;
	int		i;
	int		j;
	int		i_i;
	int		j_i;

	i = 0;
	// while (i < img->h)
	while (i < size)
	{
		j = 0;
		// while (j < img->w)
		while (j < size)
		{
			i_i = (i / (size / img->h));
			j_i = (j / (size / img->w));
			dst = img->addr + (i_i * img->line_length + j_i * (img->bits_per_pixel / 8));
			dst_screen = screen->addr + ((y + i) * screen->line_length + (x + j) * (screen->bits_per_pixel / 8));
			*(unsigned int*)dst_screen = *(unsigned int*)dst;
			j++;
		}
		i++;
	}
}

void	raycasting(t_mlx *mlx)
{
	int		x;
	int		map_x;
	int		map_y;
	double	cam_x;
	double	ray_x;
	double	ray_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	w_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		height_dr;
	int		dr_start;
	int		dr_end;
	int		color;

	x = 0;
	while (x < mlx->screen.w)
	{
		cam_x = 2 * x / (double)mlx->screen.w;
		ray_x = mlx->player.dir_x + mlx->player.plane_x * cam_x;
		ray_y = mlx->player.dir_y + mlx->player.plane_y * cam_x;

		map_x = (int) mlx->player.x;
		map_y = (int) mlx->player.y;

		if (ray_x == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = abs(1 / ray_x);
		if (ray_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = abs(1 / ray_y);
		hit = 0;
		x++;
	}

}
