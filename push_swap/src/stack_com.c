/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_com.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:57:30 by decordel          #+#    #+#             */
/*   Updated: 2022/01/15 21:00:09 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*new_stack(int n, size_t i)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof (new));
	if (!new)
		return (NULL);
	new->index = i;
	new->n = n;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stclast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *newl)
{
	t_stack	*head;

	head = *lst;
	if (!head)
	{
		*lst = newl;
		return ;
	}
	head = ft_stclast(head);
	head->next = newl;
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;

	head = *stack;
	if (stack)
	{
		while (head)
		{
			next = head->next;
			free(head);
			head = next;
		}
	}
	*stack = NULL;
}
