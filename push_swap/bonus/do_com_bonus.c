/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_com_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:42:56 by decordel          #+#    #+#             */
/*   Updated: 2022/01/24 22:16:29 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_com_gnl(t_data *data, char *com)
{
	if (!ft_strncmp(com, "ss\n", 4))
		do_swap(data, NULL);
	else if (!ft_strncmp(com, "sa\n", 4))
		do_swap(data, data->a);
	else if (!ft_strncmp(com, "sb\n", 4))
		do_swap(data, data->b);
	else if (!ft_strncmp(com, "pa\n", 4))
		do_push(data, data->a);
	else if (!ft_strncmp(com, "pb\n", 4))
		do_push(data, data->b);
	else if (!ft_strncmp(com, "ra\n", 4))
		do_rotate(data, data->a);
	else if (!ft_strncmp(com, "rb\n", 4))
		do_rotate(data, data->b);
	else if (!ft_strncmp(com, "rr\n", 4))
		do_rotate(data, NULL);
	else if (!ft_strncmp(com, "rra\n", 5))
		do_reverse(data, data->a);
	else if (!ft_strncmp(com, "rrb\n", 5))
		do_reverse(data, data->b);
	else if (!ft_strncmp(com, "rrr\n", 5))
		do_reverse(data, NULL);
	else
		ft_put_err("Error");
}

void	read_gnl(t_data *data)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		do_com_gnl(data, str);
		free(str);
		str = get_next_line(0);
	}
	// print_stacks(data);
	if (check_sort_data(data))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
