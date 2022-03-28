/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:48:37 by decordel          #+#    #+#             */
/*   Updated: 2021/10/26 17:59:22 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_d_type(int n, int fd, size_t *counter)
{
	char	c;

	if (n == -2147483647 - 1)
	{
		write(fd, "-2147483648", 11);
		*counter += 11;
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		(*counter)++;
		n = -n;
	}
	c = n % 10 + '0';
	if (n / 10 == 0)
	{
		write(fd, &c, 1);
		(*counter)++;
		return ;
	}
	ft_d_type(n / 10, fd, counter);
	write(fd, &c, 1);
	(*counter)++;
}
