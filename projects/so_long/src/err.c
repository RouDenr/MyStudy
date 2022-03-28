/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:33:35 by decordel          #+#    #+#             */
/*   Updated: 2021/12/07 21:19:46 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_error(char *err)
{
	ft_putstr_fd("so_long: ", 2);
	ft_putendl_fd(err, 2);
	exit(1);
}

void	*check_malloc(int size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		put_error("malloc err");
	return (mem);
}
