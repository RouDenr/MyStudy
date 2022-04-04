/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:27:57 by decordel          #+#    #+#             */
/*   Updated: 2022/04/03 22:47:23 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	return_code = 0;

int main(int argc, char const *argv[])
{
	char *str;

	if (argc > 1)
		return (1);
	(void) argv;
	while (1)
	{
		str = readline("minishell$> ");
	}
	return 0;
}
