/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:12:12 by decordel          #+#    #+#             */
/*   Updated: 2021/10/09 21:06:42 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cdst;
	size_t				i;
	size_t				diff;

	cdst = dst;
	diff = dst - src;
	i = -1;
	while (++i < n && (dst || src))
		cdst[i] = cdst[i - diff];
	return (cdst);
}
