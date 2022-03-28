/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:26:14 by decordel          #+#    #+#             */
/*   Updated: 2021/12/09 14:03:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *newl)
{
	t_list	*head;

	head = *lst;
	if (!head)
	{
		*lst = newl;
		return ;
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = newl;
}
