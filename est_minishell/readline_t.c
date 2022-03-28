/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:58:30 by decordel          #+#    #+#             */
/*   Updated: 2022/03/28 17:41:01 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
// #include <readline/history.h>

int main(int argc, char const *argv[])
{
	while (1)
	{
		printf("1\n");
		// char *str = readline("minishell > ");
		read(0, NULL, 1);
		// free(str);
	}

	return 0;
}
