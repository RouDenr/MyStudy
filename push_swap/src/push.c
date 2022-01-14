/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:31:55 by decordel          #+#    #+#             */
/*   Updated: 2022/01/13 18:56:52 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack **in, t_stack **out)
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
