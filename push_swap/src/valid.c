/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:54:19 by decordel          #+#    #+#             */
/*   Updated: 2022/01/14 21:20:47 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_num_in_args(char **argv)
{
	argv++;
	while (*argv)
	{
		while (**argv)
		{
			if (!ft_isdigit(**argv) && **argv != ' ' && **argv != '-')
				ft_put_err("Error\nnot int in args");
			(*argv)++;
		}
		argv++;
	}
}

int	find_dup(t_stack *stack, int n)
{
	if (stack->next == NULL)
		return (0);
	return (n == stack->next->n || find_dup(stack->next, n)
		|| find_dup(stack->next, stack->next->n));
}
