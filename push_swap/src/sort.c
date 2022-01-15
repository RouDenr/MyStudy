/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:05 by decordel          #+#    #+#             */
/*   Updated: 2022/01/15 22:56:32 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_com(t_data *data, char *com)
{
	ft_putendl_fd(com, 1);
	data->count_oper++;
}

void	sort_three(t_data *data, t_stack *stack)
{
	t_stack	*min;

	min = ft_stack_which_min_index(stack);
	if (stack == min)
		do_rotate(data, stack);
	else if (stack->index == 2)
		do_reverse(data, stack);
	else if (stack->next == min)
		do_rotate(data, stack);
	else
		do_swap(data, stack);
}

void	min_to_up(t_data *data, t_stack *stack)
{
	t_stack	*min;

	min = ft_stack_which_min_index(stack);
	if (is_first_part_stack(stack, min))
		rotate_to_top(data, stack, min);
	else
		reverse_to_top(data, stack, min);
	do_push(data, stack);
}

void	sort_first_three(t_data *data, t_stack *stack)
{
	(void) data;
	(void) stack;
}

void	sorting(t_data *data)
{
	int	count;

	while (!check_sort(data))
	{
		count = ft_stccount(data->a);
		sort_index(data->a);
		sort_index(data->b);
		if (count == 2)
			do_rotate(data, data->a);
		else if (count == 3)
			sort_three(data, data->a);
		else if (count < 5)
			min_to_up(data, data->a);
	}
}
