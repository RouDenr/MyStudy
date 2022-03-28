/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:54:30 by decordel          #+#    #+#             */
/*   Updated: 2022/03/04 23:41:14 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

t_fork	*new_fork(int forks, int need_ate)
{
	t_fork		*new;

	new = (t_fork *)malloc(sizeof (t_fork));
	if (!new)
		return (NULL);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_CHECK_ATE);
	sem_unlink(SEM_CHECK_DEAD);
	new->forks = sem_open(SEM_FORK, O_CREAT | O_EXCL, 644, forks);
	new->all_ate = sem_open(SEM_CHECK_ATE, O_CREAT | O_EXCL, 644, 0);
	new->print = sem_open(SEM_CHECK_PRINT, O_CREAT | O_EXCL, 644, 0);
	new->all_alive = sem_open(SEM_CHECK_DEAD, O_CREAT | O_EXCL, 644, 0);
	(void) need_ate;
	return (new);
}

void	forks_clean(t_fork *sem)
{
	sem_unlink(SEM_CHECK_DEAD);
	sem_unlink(SEM_CHECK_ATE);
	sem_unlink(SEM_FORK);
	free(sem);
}
