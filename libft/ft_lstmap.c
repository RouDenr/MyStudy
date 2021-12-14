/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:00:22 by decordel          #+#    #+#             */
/*   Updated: 2021/12/14 17:53:59 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof (new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

static void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	if (!head)
	{
		*lst = new;
		return ;
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = new;
}

static void	lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*next;

	head = *lst;
	if (lst)
	{
		while (head)
		{
			next = head->next;
			del(head->content);
			free(head);
			head = next;
		}
	}
	*lst = NULL;
}

int	do_malloc(t_list *node, t_list *lst, t_list *map, void (*del)(void *))
{
	if (!node)
	{
		lstclear(&lst, del);
		lstclear(&map, del);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void(*del)(void *))
{
	t_list	*map;
	t_list	*clst;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	map = lstnew(f(lst->content));
	if (!do_malloc(map, lst, map, del))
		return (NULL);
	clst = lst->next;
	while (clst)
	{
		next = lstnew(f(clst->content));
		if (!do_malloc(next, lst, map, del))
			return (NULL);
		lstadd_back(&map, next);
		clst = clst->next;
	}
	return (map);
}
