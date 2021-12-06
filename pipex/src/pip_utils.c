/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:44:39 by decordel          #+#    #+#             */
/*   Updated: 2021/12/06 16:13:12 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	put_error(char *err)
{
	ft_putendl_fd(err, 2);
	exit(1);
}

char	*split_free(char **paths)
{
	size_t	i;

	if (paths)
	{
		i = -1;
		while (paths[++i])
			free(paths[i]);
		free(paths[i]);
		free(paths);
	}
	return (NULL);
}

static char	*path_com_free(char **paths, char *temp)
{
	size_t	i;

	if (temp)
		free (temp);
	if (paths)
	{
		i = -1;
		while (paths[++i])
			free(paths[i]);
		free(paths[i]);
		free(paths);
	}
	return (NULL);
}

char	*path_command(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*temp_cmp;
	int		i;

	i = -1;
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	paths = ft_split(*envp + 5, ':');
	temp_cmp = ft_strjoin("/", cmd);
	while (paths && paths[++i])
	{
		path = ft_strjoin(paths[i], temp_cmp);
		if (!path)
			break ;
		if (access(path, F_OK) == 0)
		{
			path_com_free(paths, temp_cmp);
			return (path);
		}
		free(path);
	}
	path_com_free(paths, temp_cmp);
	return (NULL);
}

void	read_gnl(char *lim, t_pip pip)
{
	char	*str;

	ft_putstr_fd("heredoc> ", 1);
	str = get_next_line(0);
	while (str)
	{
		if (!ft_strncmp(lim, str, ft_strlen(lim) + 1))
			exit(0);
		ft_putstr_fd(str, pip.fd[1]);
		free(str);
		ft_putstr_fd("heredoc> ", 1);
		str = get_next_line(0);
	}
}
