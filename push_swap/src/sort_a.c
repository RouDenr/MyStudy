/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 06:13:19 by decordel          #+#    #+#             */
/*   Updated: 2022/01/22 23:47:38 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_a(t_data *data, t_stack *stack)
{
	t_stack	*min;

	min = ft_stack_which_min_index(stack);
	if (stack == min)
		do_rotate(data, stack);
	else if (stack != min && stack != ft_stack_which_max_index(stack))
		do_reverse(data, stack);
	else if (stack->next == min)
		do_rotate(data, stack);
	else
		do_swap(data, stack);
}

void	sort_less_five_a(t_data *data, int n)
{
	int	count;

	while (!check_sort_stack(data->a))
	{
		count = ft_stccount(data->a);
		if (count == 2)
			do_rotate(data, data->a);
		else if (count == 3)
			sort_three_a(data, data->a);
		else
			ft_push_top(data, data->a, ft_stack_which_min_index(data->a));
	}
	while (data->b && count++ != n)
		ft_push_top(data, data->b, ft_stack_index(data->b, data->a->index - 1));
}
