/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:31:58 by decordel          #+#    #+#             */
/*   Updated: 2022/01/15 22:23:55 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = *stack;
	*stack = head->next;
	last = ft_stclast(head);
	last->next = head;
	head->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	do_rotate(t_data *data, t_stack *stack)
{
	if (stack == data->a)
	{
		rotate(&(data->a));
		do_com(data, "ra");
	}
	else if (stack == data->b)
	{
		rotate(&(data->b));
		do_com(data, "rb");
	}
	else
	{
		rr(&(data->a), &(data->a));
		do_com(data, "rr");
	}
}

void	rotate_to_top(t_data *data, t_stack *top, t_stack *stack)
{
	while (stack != top)
		do_reverse(data, top);
}
