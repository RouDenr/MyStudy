/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:30:08 by decordel          #+#    #+#             */
/*   Updated: 2022/02/24 00:28:39 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

t_philo_info	*get_philo(t_data *data, t_philo *philo)
{
	t_philo_info	*info;

	info = (t_philo_info *)malloc(sizeof (t_philo_info));
	info->data = data;
	info->philo = philo;
	return (info);
}

t_philo	*new_philo(void)
{
	t_philo		*new;
	static int	n = 1;

	new = (t_philo *)malloc(sizeof (t_philo));
	if (!new)
		return (NULL);
	new->n_p = n++;
	new->count_eat = 0;
	new->last_eat = 0;
	new->fork_free = 1;
	pthread_mutex_init(&(new->fork), NULL);
	new->next = NULL;
	return (new);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *newl)
{
	t_philo	*head;

	head = *lst;
	if (!head)
	{
		*lst = newl;
		return ;
	}
	head = ft_lstlast(head);
	head->next = newl;
}

void	ft_philoclear(t_philo **stack)
{
	t_philo	*head;
	t_philo	*next;

	head = *stack;
	if (stack)
	{
		while (head)
		{
			next = head->next;
			pthread_mutex_destroy(&(head->fork));
			free(head);
			head = next;
		}
	}
	*stack = NULL;
}
