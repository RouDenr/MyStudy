/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:48:26 by decordel          #+#    #+#             */
/*   Updated: 2022/06/06 23:22:24 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx_mms/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_player
{
	int		x;
	int		y;
}				t_player;

typedef struct s_map
{
	char		**data;
	int			w;
	int			h;
}				t_map;

typedef struct s_mlx
{
	void		*init;
	void		*win;
	t_map		map;
	t_player	player;

}				t_mlx;

void	init_map(char *path_map, t_mlx *mlx);
int		check_invalid_items(char *map);
void	find_pl(t_player *player, char **data);
int		check_wall(char **map);

#endif
