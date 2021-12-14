/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:31:26 by decordel          #+#    #+#             */
/*   Updated: 2021/12/14 00:29:52 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_size_map(t_map *map)
{
	int	i;

	i = 0;
	map->h = 0;
	map->w = 0;
	while (map->data[0][i++])
		map->w += SPRITE_W;
	i = 0;
	while (map->data[i++])
		map->h += SPRITE_H;
}

static int	read_char(int fd, char *c)
{
	int		len;

	len = read(fd, c, 1);
	if (!len)
		return (0);
	if (len < 0)
		put_error("ошибка чтения карты");
	return (1);
}

char	*read_all(int fd)
{
	int		size;
	int		i;
	char	*str;
	char	*temp;
	char	c;

	size = 1;
	str = (char *)check_malloc(sizeof(char));
	str[0] = '\0';
	while (read_char(fd, &c))
	{
		size++;
		temp = (char *)check_malloc(size * sizeof(char));
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

void	check_map(char *path_map, t_map *map)
{
	int		fd;
	char	*line;

	if (ft_strnendcmp(path_map, ".ber", 4))
		put_error("карта должна иметь расщирение .ber");
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		put_error("ошибка открытия");
	line = read_all(fd);
	check_rectangle(line);
	check_invalid_items(line);
	check_items(line);
	map->data = ft_split(line, '\n');
	if (!map->data)
		put_error("malloc error");
	free(line);
	check_wall(map->data);
}

int	check_map_win(char **data, t_mlx *mlx)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	while (data[++j])
	{
		i = 0;
		while (data[j][++i])
			if (data[j][i] == 'C')
				return (0);
	}
	mlx->map.img_exit = mlx_xpm_file_to_image(mlx->init, "img/door_o.xpm",
			&x, &y);
	return (1);
}
