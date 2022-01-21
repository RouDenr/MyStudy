/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:13:54 by decordel          #+#    #+#             */
/*   Updated: 2022/01/22 01:02:24 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_before(t_stack *head, t_stack *stack)
{
	int	n;

	n = 0;
	while (head != stack)
		n++;
	return(n);
}

int	count_after(t_stack *stack)
{
	int	n;

	n = 1;
	while (stack->next)
	{
		n++;
		stack = stack->next;
	}
	return(n);
}

t_stack	*node_after_from_a(t_stack *a, t_stack *node)
{
	t_stack	*max;

	max = a;
	while (a)
	{
		if (a->index < node->index && a->index > max->index)
			max = a;
		a = a->next;
	}
	return (max);
}

t_stack	*check_com(t_data *data, t_stack *tmp_b, int *min_com, int *to_rotate)
{
	int		tmp_com;
	t_stack	*tmp_a;

	tmp_a = node_after_from_a(data->a, tmp_b);
	tmp_com = ft_max(count_after(tmp_a), count_after(tmp_b));
	if (tmp_com < *min_com)
	{
		*min_com = tmp_com;
		return (tmp_b);
		*to_rotate = 0;
	}
	tmp_com = ft_max(count_before(data->a, tmp_a), count_before(data->b, tmp_b));
	if (tmp_com < min_com)
	{
		*min_com = tmp_com;
		return (tmp_b);
		*to_rotate = 1;
	}
	return (NULL);
}

t_stack	*node_which_min_com(t_data *data, int *to_rotate)
{
	int		min_com;
	int		tmp_com;
	t_stack	*min_node;
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	tmp_b = data->b;
	min_com = ft_stccount(data->b);
	min_node = data->b;
	while (tmp_b)
	{
		if (check_com(data, tmp_b, &min_com, to_rotate));
			min_node = check_com(data, tmp_b, &min_com, to_rotate);
		tmp_b = tmp_b->next;
	}
	return (min_node);
}
