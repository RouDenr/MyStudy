/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:54:19 by decordel          #+#    #+#             */
/*   Updated: 2022/01/15 20:09:59 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_num_in_args(char **argv)
{
	argv++;
	while (*argv)
	{
		while (**argv)
		{
			if (!ft_isdigit(**argv) && **argv != ' ' && **argv != '-')
				ft_put_err("Error\nnot int in args");
			(*argv)++;
		}
		argv++;
	}
}

void	swap_index(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

void	sort_index(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		index;

	i = stack;
	index = 1;
	while (i && i->next)
	{
		j = stack;
		while (j)
		{
			if (j->index > index && i->n > j->n)
			{
				swap_index(i, j);
				i = j;
			}
			j = j->next;
		}
		i = ft_stack_which_index(stack, ++index);
	}
}

int	find_dup(t_stack *stack, int n)
{
	if (stack->next == NULL)
		return (0);
	return (n == stack->next->n || find_dup(stack->next, n)
		|| find_dup(stack->next, stack->next->n));
}

int	check_sort(t_data *data)
{
	t_stack	*tmp_a;

	tmp_a = data->a;
	if (data->b)
		return (0);
	while (tmp_a->next && tmp_a)
	{
		if (tmp_a->n > tmp_a->next->n)
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}
