/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:28:28 by decordel          #+#    #+#             */
/*   Updated: 2021/11/01 20:17:42 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_s_type(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		return (ft_s_type("(null)", 1));
	}
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
