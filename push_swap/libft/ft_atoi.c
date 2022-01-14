/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:44:33 by decordel          #+#    #+#             */
/*   Updated: 2022/01/14 21:29:26 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (1);
	if (s == '\v' || s == '\f' || s == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i++] - '0');
		if (n * sign > 2147483647)
			ft_put_err("Error\n some arguments are bigger than an integer");
		if (n * sign < -2147483648)
			ft_put_err("Error\n some arguments are lower than an integer");
	}
	return (n * sign);
}
