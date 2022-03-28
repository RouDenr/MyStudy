/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:02:09 by decordel          #+#    #+#             */
/*   Updated: 2021/11/01 17:00:21 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/ft_printf.h"
#include <stdarg.h>

void	checkf(va_list args, char f, size_t *j)
{
	if (f == 'c')
		*j += ft_c_type(va_arg(args, int), 1);
	if (f == 's')
		*j += ft_s_type(va_arg(args, char *), 1);
	if (f == 'p')
		*j += ft_p_type(va_arg(args, long));
	if (f == 'd' || f == 'i')
		ft_d_type(va_arg(args, int), 1, j);
	if (f == 'u')
		ft_u_type(va_arg(args, unsigned int), 1, j);
	if (f == 'x')
		ft_x_type(va_arg(args, unsigned int), "0123456789abcdef", 1, j);
	if (f == 'X')
		ft_x_type(va_arg(args, unsigned int), "0123456789ABCDEF", 1, j);
	if (f == '%')
		*j += ft_c_type('%', 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i++], 1);
			j++;
		}
		else
		{
			i++;
			checkf(args, str[i], &j);
			i++;
		}
	}
	va_end(args);
	return (j);
}
