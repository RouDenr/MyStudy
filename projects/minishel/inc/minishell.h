/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:24:37 by decordel          #+#    #+#             */
/*   Updated: 2022/04/18 19:42:10 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H
# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>

char	**parsing(char *s);
void	ft_exec(char *str, char **envp);
void	ft_exit(char *arg);
void	ft_env(char **envp);

#endif
