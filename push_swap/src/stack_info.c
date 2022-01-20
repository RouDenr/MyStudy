/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:50:29 by decordel          #+#    #+#             */
/*   Updated: 2022/01/20 06:27:05 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stccount(t_stack *stack)
{
	int	n;

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

int	check_sort_data(t_data *data)
{
	t_stack	*tmp_a;

	tmp_a = data->a;
	if (data->b)
		return (0);
	while (tmp_a->next && tmp_a)
	{
		if (tmp_a->n > tmp_a->next->n)
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}

int	check_sort_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_resort_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->n < tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	end_sort(t_stack *stack)
{
	stack = ft_stack_which_index(stack, 1);
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->index != stack->next->index - 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}
