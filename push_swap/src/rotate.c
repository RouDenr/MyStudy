/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:31:58 by decordel          #+#    #+#             */
/*   Updated: 2022/01/13 18:26:49 by decordel         ###   ########.fr       */
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
