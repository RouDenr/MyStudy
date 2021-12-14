/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:19:46 by decordel          #+#    #+#             */
/*   Updated: 2021/11/01 17:04:14 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_x_type(unsigned int n, const char *base, int z, size_t *counter)
{
	if (z && !n)
	{
		write(1, &base[n & 15], 1);
		(*counter)++;
	}
	if (n)
	{
		ft_x_type(n >> 4, base, 0, counter);
		write(1, &base[n & 15], 1);
		(*counter)++;
	}
}
