/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 06:13:21 by decordel          #+#    #+#             */
/*   Updated: 2022/01/22 23:47:17 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_b(t_data *data, t_stack *stack)
{
	t_stack	*max;

	max = ft_stack_which_max_index(stack);
	if (stack == max)
		do_rotate(data, stack);
	else if (stack != max && stack != ft_stack_which_min_index(stack))
		do_reverse(data, stack);
	else if (stack->next == max)
		do_rotate(data, stack);
	else
		do_swap(data, stack);
}

void	sort_less_five_b(t_data *data, int n)
{
	int	count;

	while (!check_resort_stack(data->b))
	{
		count = ft_stccount(data->b);
		if (count == 2)
			do_rotate(data, data->b);
		else if (count == 3)
			sort_three_b(data, data->b);
		else
			ft_push_top(data, data->b, ft_stack_which_max_index(data->b));
	}
	while (data->b)
	{
		do_push(data, data->a);
	}
	while (n--)
		if (!check_sort_data(data))
			do_rotate(data, data->a);
}
