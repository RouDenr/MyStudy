/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:05 by decordel          #+#    #+#             */
/*   Updated: 2022/01/20 06:44:24 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_more_middle(t_data *data, t_stack **in, t_stack **out)
{
	t_stack	*middle;
	int		size;
	int		tmp_size;

	middle = middle_index_steck(*in);
	size = ft_stccount(*in) / 2 + 1;
	tmp_size = ft_stccount(*in);
	while (tmp_size != size)
	{
		if ((*in)->n >= middle->n)
		{
			do_push(data, *out);
			tmp_size = ft_stccount(*in);
		}
		else
			do_rotate(data, *in);
	}
}

void	push_less_middle(t_data *data, t_stack **in, t_stack **out)
{
	t_stack	*middle;
	int		size;
	int		tmp_size;

	middle = middle_index_steck(*in);
	size = ft_stccount(*in) / 2;
	tmp_size = ft_stccount(*in);
	while (tmp_size != size)
	{
		if ((*in)->n < middle->n)
		{
			do_push(data, *out);
			tmp_size = ft_stccount(*in);
		}
		else
			do_rotate(data, *in);
	}
}

t_stack	*middle_index_steck_without_end(t_stack *stack)
{
	int	i;
	int	j;

	i = ft_stack_which_max_index(stack)->index;
	j = ft_stclast(stack)->index + 1;
	i = (i + j) / 2 + 1;
	return (ft_stack_which_index(stack, i));
}

void	push_less_middle_without_end(t_data *data, t_stack **in, t_stack **out)
{
	t_stack	*middle;
	t_stack	*end;
	int		size;
	int		tmp_size;

	end = ft_stclast(*in);
	middle = middle_index_steck_without_end(*in);
	size = (ft_stccount(*in) - end->index) / 2 + end->index;
	if (data->a->next->index == 1)
	{
		do_rotate(data, data->a);
		return ;
	}
	tmp_size = ft_stccount(*in);
	while (tmp_size != size)
	{
		if ((*in)->n < middle->n)
		{
			do_push(data, *out);
			tmp_size = ft_stccount(*in);
		}
		else
			do_rotate(data, *in);
	}
	while (!end_sort(*in))
		do_reverse(data, *in);
}

void	sorting(t_data *data)
{
	int	count;

	while (!check_sort_data(data))
	{
		count = ft_stccount(data->a);
		if (count > 5)
		{
			if (!end_sort(data->a))
				push_less_middle(data, &data->a, &data->b);
			else
				push_less_middle_without_end(data, &data->a, &data->b);
		}
		count = ft_stccount(data->a);
		if (count <= 5)
			sort_less_five_a(data, count);
		// while (data->b)
		// {
		count = ft_stccount(data->b);
		if (count > 5)
			push_more_middle(data, &data->b, &data->a);
		count = ft_stccount(data->b);
		// if (count <= 50)
			sort_less_five_b(data, count);
		// }
	}
}
