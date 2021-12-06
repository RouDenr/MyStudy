/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:17:13 by decordel          #+#    #+#             */
/*   Updated: 2021/10/12 14:39:53 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
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
