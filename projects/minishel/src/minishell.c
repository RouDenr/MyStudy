/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:27:57 by decordel          #+#    #+#             */
/*   Updated: 2022/04/04 19:26:58 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	return_code = 0;

int main(int argc, char const *argv[], char **envp)
{
	char *str;

	if (argc > 1)
		return (1);
	(void) argv;
	while (1)
	{
		str = readline("minishell$> ");
		ft_exec(str, envp);
	}
	return 0;
}
