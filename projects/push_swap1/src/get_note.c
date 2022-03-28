/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_note.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:27:22 by decordel          #+#    #+#             */
/*   Updated: 2022/01/22 23:47:38 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

t_stack	*middle_index_steck(t_stack *stack)
{
	int		i;
	int		j;
	int		size;
	t_stack	*tmp;

	i = ft_stack_which_min_index(stack)->index;
	j = ft_stack_which_max_index(stack)->index;
	size = ft_stccount(stack) / 2 + 1;
	tmp = ft_stack_index(stack, i);
	while (size)
	{
		tmp = ft_stack_index(stack, ++i);
		if (tmp)
			size--;
	}
	return (tmp);
}

t_stack	*ft_stack_index(t_stack *stack, int index)
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

t_stack	*ft_stack_which_max_index(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	if (stack)
	{
		while (stack)
		{
			if (stack->index > max->index)
				max = stack;
			stack = stack->next;
		}
	}
	return (max);
}
