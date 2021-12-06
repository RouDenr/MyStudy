/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:38:35 by decordel          #+#    #+#             */
/*   Updated: 2021/10/09 03:35:43 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*buf1;
	const unsigned char	*buf2;
	int					i;

	buf1 = (unsigned char *) s1;
	buf2 = (unsigned char *) s2;
	i = 0;
	while (n-- > 0 && (buf1[i] || buf2[i]))
	{
		if (buf1[i] != buf2[i])
			return (buf1[i] - buf2[i]);
		i++;
	}
	return (0);
}
