/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:18:40 by decordel          #+#    #+#             */
/*   Updated: 2021/12/09 13:14:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int c, char **v)
{
	t_mlx	mlx;

	if (c != 2)
		put_error("./so_long map.ber");
	check_map(v[1], &mlx.map);
	win_init(&mlx);
	printf("%d %d", mlx.map.w, mlx.map.h);
	return (0);
}
