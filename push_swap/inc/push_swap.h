/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:31:23 by decordel          #+#    #+#             */
/*   Updated: 2022/01/14 21:33:25 by decordel         ###   ########.fr       */
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

void	swap(t_stack **stack);
void	push(t_stack **in, t_stack **out);
void	rotate(t_stack **stack);
void	reverse(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
t_stack	*new_stack(int n, size_t i);
void	ft_stackadd_back(t_stack **lst, t_stack *newl);
int		find_dup(t_stack *stack, int n);
void	ft_stackclear(t_stack **stack);
t_stack	*ft_stclast(t_stack *lst);
void	print_stacks(t_data *data);
void	check_num_in_args(char **argv);

#endif
