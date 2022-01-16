/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:31:23 by decordel          #+#    #+#             */
/*   Updated: 2022/01/16 21:49:51 by decordel         ###   ########.fr       */
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
	size_t	count_oper;
}	t_data;

void	do_swap(t_data *data, t_stack *stack);
void	do_push(t_data *data, t_stack *stack);
void	do_rotate(t_data *data, t_stack *stack);
void	rotate_to_top(t_data *data, t_stack *top, t_stack *stack);
void	do_reverse(t_data *data, t_stack *stack);
void	reverse_to_top(t_data *data, t_stack *top, t_stack *stack);
t_stack	*new_stack(int n, size_t i);
void	ft_stackadd_back(t_stack **lst, t_stack *newl);
int		find_dup(t_stack *stack, int n);
void	ft_stackclear(t_stack **stack);
t_stack	*ft_stclast(t_stack *lst);
t_stack	*ft_stack_which_index(t_stack *stack, int index);
t_stack	*ft_stack_which_min_index(t_stack *stack);
void	print_stacks(t_data *data);
void	check_num_in_args(char **argv);
int		check_sort_data(t_data *data);
int		check_sort_stack(t_stack *stack);
void	sort_index(t_stack *stack);
int		ft_stccount(t_stack *stack);
void	sorting(t_data *data);
void	sort_a(t_data *data);
void	do_com(t_data *data, char *com);
int		is_first_part_stack(t_stack *stack, t_stack *n);
void	ft_push_to_top(t_data *data, t_stack *stack, t_stack *n);

#endif
