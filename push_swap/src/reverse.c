/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:31:52 by decordel          #+#    #+#             */
/*   Updated: 2022/01/22 23:48:18 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = *stack;
	last = head;
	while (last->next->next)
		last = last->next;
	*stack = last->next;
	last->next = NULL;
	(*stack)->next = head;
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
}

void	do_reverse(t_data *data, t_stack *stack)
{
	if (stack == data->a)
	{
		reverse(&(data->a));
		do_com(data, "rra");
	}
	else if (stack == data->b)
	{
		reverse(&(data->b));
		do_com(data, "rrb");
	}
	else
	{
		rrr(&(data->a), &(data->a));
		do_com(data, "rrr");
	}
}

void	reverse_to_top(t_data *data, t_stack *top, t_stack *stack)
{
	if (data->a == top)
	{
		while (stack != data->a)
			do_reverse(data, data->a);
		do_push(data, data->b);
	}
	else if (data->b == top)
	{
		while (stack != data->b)
			do_reverse(data, data->b);
		do_push(data, data->a);
	}
}
