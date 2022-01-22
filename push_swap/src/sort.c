/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:05 by decordel          #+#    #+#             */
/*   Updated: 2022/01/22 23:48:02 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sorting(t_data *data)
{
	t_stack	*min;
	t_stack	*max;
	int		count;

	min = ft_stack_which_min_index(data->a);
	max = ft_stack_which_max_index(data->a);
	count = ft_stccount(data->a);
	if (count <= 5)
		sort_less_five_a(data->a, count);
	while (count != 2)
	{
		if (data->a != min && data->a != max)
			do_push(data, data->b);
		else
			do_rotate(data, data->a);
		count = ft_stccount(data->a);
	}
}
