/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:31:26 by decordel          #+#    #+#             */
/*   Updated: 2022/06/06 23:22:49 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_size_map(t_map *map)
{
	int	i;

	i = 0;
	map->h = 0;
	map->w = 0;
	while (map->data[0][i++])
		map->w++;
	i = 0;
	while (map->data[i++])
		map->h++;
}

static int	read_char(int fd, char *c)
{
	int		len;

	len = read(fd, c, 1);
	if (!len)
		return (0);
	if (len < 0)
		ft_put_err("ошибка чтения карты");
	return (1);
}

static char	*read_all(int fd)
{
	int		size;
	int		i;
	char	*str;
	char	*temp;
	char	c;

	size = 1;
	str = (char *)check_calloc(1, sizeof(char));
	str[0] = '\0';
	while (read_char(fd, &c))
	{
		size++;
		temp = (char *)check_calloc(size, sizeof(char));
		i = -1;
		while (++i < size - 2)
			temp[i] = str[i];
		temp[i] = c;
		temp[i + 1] = '\0';
		free(str);
		str = temp;
	}
	return (str);
}

void	init_map(char *path_map, t_mlx *mlx)
{
	int		fd;
	char	*line;

	if (ft_strnendcmp(path_map, ".cub", 5))
		ft_put_err("карта должна иметь расщирение .cub");
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		ft_put_err("ошибка открытия");
	line = read_all(fd);
	check_invalid_items(line);
	mlx->map.data = ft_split(line, '\n');
	if (!mlx->map.data)
		ft_put_err("malloc error");
	find_pl(&mlx->player, mlx->map.data);
	free(line);
	check_wall(mlx->map.data);
}

// int	check_map_win(char **data, t_mlx *mlx)
// {
// 	int	i;
// 	int	j;
// 	int	x;
// 	int	y;

// 	j = 0;
// 	while (data[++j])
// 	{
// 		i = 0;
// 		while (data[j][++i])
// 			if (data[j][i] == 'C')
// 				return (0);
// 	}
// 	mlx->map.img_exit = mlx_xpm_file_to_image(mlx->init, "img/door_o.xpm",
// 			&x, &y);
// 	return (1);
// }
