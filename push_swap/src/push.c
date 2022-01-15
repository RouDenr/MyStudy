/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:31:55 by decordel          #+#    #+#             */
/*   Updated: 2022/01/15 21:49:48 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack **in, t_stack **out)
{
	t_stack	*tmp;

	tmp = *in;
	*in = tmp->next;
	if (*out == NULL)
	{
		tmp->next = NULL;
		*out = tmp;
		return ;
	}
	tmp->next = *out;
	*out = tmp;
}

void	do_push(t_data *data, t_stack *stack)
{
	if (stack == data->a)
	{
		push(&(data->b), &(data->a));
		do_com(data, "pa");
	}
	else
	{
		push(&(data->a), &(data->b));
		do_com(data, "pb");
	}
}
