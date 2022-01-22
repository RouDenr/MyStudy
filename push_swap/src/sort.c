/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:05 by decordel          #+#    #+#             */
/*   Updated: 2022/01/23 02:57:16 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void rotate_sort(t_data *data, t_stack *node_b)
{
	t_stack	*node_a;

	node_a = node_after_from_a(data->a, node_b);
	// ft_printf("%d - a %d - b\n", node_a->index, node_b->index);
	// print_stacks(data);
	while (node_b != data->b || node_a != data->a)
	{
		if (node_b != data->b && node_a != data->a)
			do_rotate(data, NULL);
		else if (node_b != data->b)
			do_rotate(data, data->b);
		else if (node_a != data->a)
			do_rotate(data, data->a);
	}
	do_push(data, data->a);
}

void reverse_sort(t_data *data, t_stack *node_b)
{
	t_stack	*node_a;

	// print_stacks(data);
	node_a = node_after_from_a(data->a, node_b);
	while (node_b != data->b || node_a != data->a)
	{
		if (node_b != data->b && node_a != data->a)
			do_reverse(data, NULL);
		else if (node_b != data->b)
			do_reverse(data, data->b);
		else if (node_a != data->a)
			do_reverse(data, data->a);
	}
	do_push(data, data->a);
}

void	sort_min_com(t_data *data)
{
	t_stack	*node;
	int		to_rotate;

	to_rotate = 1;
	while (data->b)
	{
		// print_stacks(data);
		node = node_which_min_com(data, &to_rotate);
		if (to_rotate)
			rotate_sort(data, node);
		else
			reverse_sort(data, node);
	}
	node = ft_stack_index(data->a, 1);
	while (!check_sort_data(data))
	{
		// print_stacks(data);
		if (!is_first_part_stack(data->a, node))
			do_reverse(data, data->a);
		else
			do_rotate(data, data->a);
	}
}

void	sorting(t_data *data)
{
	t_stack	*min;
	t_stack	*max;
	t_stack	*mid;
	int		count;

	min = ft_stack_which_min_index(data->a);
	max = ft_stack_which_max_index(data->a);
	mid = middle_index_steck(data->a);
	// print_stacks(data);
	count = ft_stccount(data->a);
	if (count <= 5)
		sort_less_five_a(data, count);
	while (count != 2)
	{
		if (data->a != min && data->a != max)
		{
			do_push(data, data->b);
			if (data->b->index < mid->index)
				do_rotate(data, data->b);
		}
		else
			do_rotate(data, data->a);
		count = ft_stccount(data->a);
	}
	sort_min_com(data);
}
