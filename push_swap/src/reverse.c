/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:31:52 by decordel          #+#    #+#             */
/*   Updated: 2022/01/13 18:41:32 by decordel         ###   ########.fr       */
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
