/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:32:01 by decordel          #+#    #+#             */
/*   Updated: 2022/01/24 21:58:30 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*head;

	if (!*stack)
		return ;
	head = *stack;
	*stack = head->next;
	head->next = (*stack)->next;
	(*stack)->next = head;
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	do_swap(t_data *data, t_stack *stack)
{
	if (stack == data->a)
	{
		swap(&(data->a));
		do_com(data, "sa");
	}
	else if (stack == data->b)
	{
		swap(&(data->b));
		do_com(data, "sb");
	}
	else
	{
		ss(&(data->a), &(data->a));
		do_com(data, "ss");
	}
}
