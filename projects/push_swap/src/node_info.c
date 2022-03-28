/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:13:54 by decordel          #+#    #+#             */
/*   Updated: 2022/01/24 21:13:01 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate_com(t_stack *head, t_stack *stack)
{
	int	n;

	n = 0;
	while (head && head != stack)
	{
		n++;
		head = head->next;
	}
	return (n);
}

int	reverse_com(t_stack *stack)
{
	int	n;

	n = 1;
	while (stack->next)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

void	set_rotate(t_sort *rotate, int a, int b, int tmp_com)
{
	rotate->min_com = tmp_com;
	rotate->a = a;
	rotate->b = b;
}

t_stack	*check_com(t_data *data, t_stack *tmp_a, t_stack *tmp_b, t_sort *rotate)
{
	int		tmp_com;
	t_stack	*tmp;

	tmp = NULL;
	tmp_com = ft_min(reverse_com(tmp_a), rotate_com(data->a, tmp_a));
	tmp_com += ft_min(reverse_com(tmp_b), rotate_com(data->b, tmp_b));
	if (tmp_com < rotate->min_com)
	{
		set_rotate(rotate, reverse_com(tmp_a) > rotate_com(data->a, tmp_a),
			reverse_com(tmp_b) > rotate_com(data->b, tmp_b), tmp_com);
		tmp = tmp_b;
	}
	tmp_com = ft_max(rotate_com(data->a, tmp_a), rotate_com(data->b, tmp_b));
	if (tmp_com <= rotate->min_com)
	{
		set_rotate(rotate, 1, 1, tmp_com);
		tmp = tmp_b;
	}
	tmp_com = ft_max(reverse_com(tmp_a), reverse_com(tmp_b));
	if (tmp_com <= rotate->min_com)
	{
		set_rotate(rotate, 0, 0, tmp_com);
		tmp = tmp_b;
	}
	return (tmp);
}

t_stack	*node_which_min_com(t_data *data, t_sort *rotate)
{
	t_stack	*min_node;
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*tmp;

	tmp_b = data->b;
	rotate->min_com = ft_stccount(data->b) + ft_stccount(data->a);
	min_node = data->b;
	while (tmp_b)
	{
	tmp_a = node_after_from_a(data->a, tmp_b);
		tmp = check_com(data, tmp_a, tmp_b, rotate);
		if (tmp)
			min_node = tmp_b;
		tmp_b = tmp_b->next;
	}
	return (min_node);
}
