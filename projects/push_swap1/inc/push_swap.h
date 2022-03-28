/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:31:23 by decordel          #+#    #+#             */
/*   Updated: 2022/01/24 22:10:15 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				n;
	int				index;

}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		count_oper;
}	t_data;

typedef struct s_bool_sort
{
	int		a;
	int		b;
	int		min_com;
}	t_sort;

void	do_swap(t_data *data, t_stack *stack);
void	do_push(t_data *data, t_stack *stack);
void	do_rotate(t_data *data, t_stack *stack);
void	do_reverse(t_data *data, t_stack *stack);
void	rotate_to_top(t_data *data, t_stack *top, t_stack *stack);
void	reverse_to_top(t_data *data, t_stack *top, t_stack *stack);
t_stack	*new_stack(int n, size_t i);
t_stack	*ft_stclast(t_stack *lst);
t_stack	*middle_steck(t_stack *stack);
t_stack	*middle_index_steck(t_stack *stack);
t_stack	*node_which_min_com(t_data *data, t_sort *rotate);
t_stack	*node_after_from_a(t_stack *a, t_stack *node);
t_stack	*ft_stack_index(t_stack *stack, int index);
t_stack	*ft_stack_which_min_index(t_stack *stack);
t_stack	*ft_stack_which_max_index(t_stack *stack);
void	ft_stackclear(t_stack **stack);
void	ft_stackadd_back(t_stack **lst, t_stack *newl);
void	ft_push_top(t_data *data, t_stack *stack, t_stack *n);
void	print_stacks(t_data *data);
void	sort_index(t_stack *stack);
void	sorting(t_data *data);
void	sort_three_a(t_data *data, t_stack *stack);
void	sort_three_b(t_data *data, t_stack *stack);
void	sort_less_five_a(t_data *data);
void	do_com(t_data *data, char *com);
int		ft_stccount(t_stack *stack);
void	check_num_in_args(char **argv);
int		find_dup(t_stack *stack);
int		check_sort_data(t_data *data);
int		check_sort_stack(t_stack *stack);
int		is_first_part_stack(t_stack *stack, t_stack *n);
int		end_sort(t_stack *stack);
void	read_gnl(t_data *data);

#endif
