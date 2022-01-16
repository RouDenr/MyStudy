/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:05 by decordel          #+#    #+#             */
/*   Updated: 2022/01/16 22:11:37 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_com(t_data *data, char *com)
{
	ft_putendl_fd(com, 1);
	data->count_oper++;
	// print_stacks(data);
}

void	sort_three(t_data *data, t_stack *stack)
{
	t_stack	*min;

	min = ft_stack_which_min_index(stack);
	if (stack == min)
		do_rotate(data, stack);
	else if (stack->index == min->index + 1)
		do_reverse(data, stack);
	else if (stack->next == min)
		do_rotate(data, stack);
	else
		do_swap(data, stack);
}

void	min_to_b(t_data *data, t_stack *stack)
{
	t_stack	*min;

	min = ft_stack_which_min_index(stack);
	if (is_first_part_stack(stack, min))
		rotate_to_top(data, stack, min);
	else
		reverse_to_top(data, stack, min);
	while (!check_sort_stack(data->a))
		sort_a(data);
	while (data->b)
		do_push(data, data->a);
}

void	sort_first_three(t_data *data, t_stack *stack)
{
	(void) data;
	(void) stack;
}

void	sorting(t_data *data)
{
	sort_a(data);
	while (data->b)
		do_push(data, data->a);
}

void	sort_a(t_data *data)
{
	int	count;

	while (!check_sort_stack(data->a))
	{
		count = ft_stccount(data->a);
		if (count == 2)
			do_rotate(data, data->a);
		else if (count == 3)
			sort_three(data, data->a);
		else
			ft_push_to_top(data, data->a, ft_stack_which_min_index(data->a));
		// print_stacks(data);
	}
}
