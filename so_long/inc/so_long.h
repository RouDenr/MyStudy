/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:29:27 by decordel          #+#    #+#             */
/*   Updated: 2021/12/14 00:29:50 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "libft.h"
# include "src.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	void	*img_player;
	void	*img_exit;
	void	*img_coll;
	void	*img_wall;
	void	*img_en;
	void	*img_space;
	void	*img_num[10];
	char	**data;
	int		w;
	int		h;
	int		p_x;
	int		p_y;
	int		p_right;
}				t_map;

typedef struct s_mlx
{
	void		*init;
	void		*win;
	int			steps;
	t_map		map;

}				t_mlx;

char	*read_all(int fd);
void	put_error(char *err);
void	get_size_map(t_map *map);
void	draw_map(t_mlx *mlx, t_map *map);
void	draw_num(t_mlx *mlx, void *num[], int n);
void	draw_space(t_mlx *mlx, t_map *map);
int		check_rectangle(char *map);
int		check_wall(char **map);
int		check_items(char *map);
int		check_invalid_items(char *map);
void	check_map(char *path_map, t_map *map);
int		check_map_win(char **data, t_mlx *mlx);
void	*check_malloc(int size);
void	win_init(t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
void	get_animation(t_map *map, t_mlx *mlx);
void	enemy_goes(char **map);
#endif
