/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:38:02 by decordel          #+#    #+#             */
/*   Updated: 2021/12/02 21:16:39 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# ifndef PIP
#  define PIP 
# endif
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_pip
{
	int		fd[2];
	int		pid;
	int		i;
	int		k;
}	t_pip;

char	*path_command(char *cmd, char **envp);
void	put_error(char *err);
char	*split_free(char **paths);
void	read_gnl(char *lim, t_pip pip);

#endif
