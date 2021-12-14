/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:48:37 by decordel          #+#    #+#             */
/*   Updated: 2021/11/01 20:17:57 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_u_type(unsigned int n, int fd, size_t *counter)
{
	char	c;

	c = n % 10 + '0';
	if (n / 10 == 0)
	{
		write(fd, &c, 1);
		(*counter)++;
		return ;
	}
	ft_u_type(n / 10, fd, counter);
	write(fd, &c, 1);
	(*counter)++;
}
