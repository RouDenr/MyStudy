/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:44:18 by decordel          #+#    #+#             */
/*   Updated: 2022/01/16 22:08:48 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include <stdio.h>

static void	print_content(t_stack *stack)
{
	if (stack)
		ft_putnbr_fd(stack->n, 1);
	ft_putstr_fd("\t|", 1);
	if (stack)
		ft_putnbr_fd(stack->index, 1);
}

void	print_stacks(t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = data->a;
	tmp_b = data->b;
	ft_putstr_fd("\n\033[1;32m[-------------------------------|\n", 1);
	ft_putstr_fd("|\t\033[1;31mA\033[1;32m\t|\t\033[1;34mB\033[1;32m\t|\n", 1);
	ft_putstr_fd("| \033[1;31mn\t| index\033[1;32m\t", 1);
	ft_putstr_fd("| \033[1;34mn\t| index\033[1;32m\t|\n", 1);
	ft_putstr_fd("|\033[1;31m-------|-------\033[1;32m", 1);
	ft_putstr_fd("|\033[1;34m-------|-------\033[1;32m|\n|\033[1;31m", 1);
	while (tmp_a || tmp_b)
	{
		print_content(tmp_a);
		ft_putstr_fd("\t\033[1;32m|\033[1;34m", 1);
		print_content(tmp_b);
		ft_putstr_fd("\t\033[1;32m|\n|\033[1;31m", 1);
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
	ft_putstr_fd("\033[1;32m-------------------------------]\033[0m\n\n", 1);
}

void	init_a(t_data *data, char **argv)
{
	size_t	index;
	size_t	i;
	size_t	j;
	t_stack	*tmp;
	char	**tmp_arg;

	i = 1;
	index = 1;
	while (argv[i])
	{
		tmp_arg = ft_split(argv[i++], ' ');
		j = 0;
		while (tmp_arg[j])
		{
			tmp = new_stack(ft_atoi(tmp_arg[j++]), index++);
			ft_stackadd_back(&(data->a), tmp);
		}
		split_free(tmp_arg);
	}
	sort_index(data->a);
}

int	main(int argc, char **argv)
{
	t_data	data;
	// t_stack	*a;

	if (argc == 1)
		return (0);
	data.a = NULL;
	data.b = NULL;
	data.count_oper = 0;
	init_a(&data, argv);
	check_num_in_args(argv);
	print_stacks(&data);
	// if (find_dup(data.a, data.a->n))
		// ft_put_err("Error\ndup");
	// push(&(data.a), &(data.b));
	sorting(&data);
	// a = ft_stack_which_min_index(data.a);
	// ft_putnbr_fd(a->n, 1);
	print_stacks(&data);
	ft_putnbr_fd(data.count_oper, 1);
	ft_putchar_fd('\n', 1);
	ft_stackclear(&(data.a));
	ft_stackclear(&(data.b));
	return (0);
}
