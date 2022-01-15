/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:50:29 by decordel          #+#    #+#             */
/*   Updated: 2022/01/15 22:46:51 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stack_which_index(t_stack *stack, int index)
{
	while (stack && stack->index != index)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_stack_which_min_index(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	if (stack)
	{
		while (stack)
		{
			if (stack->index < min->index)
				min = stack;
			stack = stack->next;
		}
	}
	return (min);
}

t_stack	*middle_steck(t_stack *stack)
{
	int	count;
	int	i;

	count = ft_stccount(stack);
	i = 1;
	while (i++ != count / 2 + 1)
		stack = stack->next;
	return (stack);
}

int	ft_stccount(t_stack *stack)
{
	int n;

	n = 0;
	while (stack)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

int	is_first_part_stack(t_stack *stack, t_stack *n)
{
	t_stack	*middle;

	middle = middle_steck(stack);
	while (stack != middle)
	{
		if (stack == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
