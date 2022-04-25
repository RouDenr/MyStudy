/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:27:10 by decordel          #+#    #+#             */
/*   Updated: 2022/04/17 17:08:49 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_exit(char *arg)
{
	int	i;

	if (arg)
		i = ft_atoi(arg);
	else
		i = 0;
	printf("exit\n");
	exit(i);
}

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
}
