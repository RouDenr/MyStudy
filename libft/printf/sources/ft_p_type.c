/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:12:42 by decordel          #+#    #+#             */
/*   Updated: 2021/11/01 17:09:50 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	x_type(unsigned long n, const char *b, int z, size_t *counter)
{
	if (z && !n)
	{
		write(1, &b[n & 15], 1);
		(*counter)++;
	}
	if (n)
	{
		x_type(n >> 4, b, 0, counter);
		write(1, &b[n & 15], 1);
		(*counter)++;
	}
	return (*counter);
}

size_t	ft_p_type(long n)
{
	size_t	i;

	i = 2;
	write(1, "0x", 2);
	x_type(n, "0123456789abcdef", 1, &i);
	return (i);
}
