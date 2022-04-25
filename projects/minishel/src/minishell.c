/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:27:57 by decordel          #+#    #+#             */
/*   Updated: 2022/04/18 20:07:04 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	return_code = 0;

int	ft_line_empty(char *line)
{
	while (*line)
		if (*line++ != ' ')
			return (0);
	return (1);
}

void print_C(int i)
{
	printf("HELLO %d", i);
}

int main(int argc, char const *argv[], char **envp)
{
	char *str;

	if (argc > 1)
		return (1);
	(void) argv;
	signal(SIGINT, print_C);
	signal(SIGTSTP, print_C);
	signal(SIGIO, print_C);
	// struct sigaction
	// sigaction(SIGINT, NULL, NULL);
	while (1)
	{
		str = readline("minishell$> ");
		if (ft_line_empty(str))
			continue ;
		ft_exec(str, envp);
	}
	return 0;
}
