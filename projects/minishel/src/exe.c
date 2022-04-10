/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:15:59 by decordel          #+#    #+#             */
/*   Updated: 2022/04/10 22:22:59 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
		if (access(path, 0) == 0)
		{
			path_com_free(paths, temp_cmp);
			return (path);
		}
		free(path);
	}
	path_com_free(paths, temp_cmp);
	return (NULL);
}

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

static void	cmd_do(char **cmd, char **envp)
{
	char	*path;

	if (access(*cmd, F_OK) == 0)
		path = *cmd;
	else
		path = path_command(*cmd, envp);
	if (path)
		execve(path, cmd, envp);
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_put_err("");
	split_free(cmd);
}

void	ft_exec(char *str, char **envp)
{
	// int	pip_fd[2];
	int	pid;
	char	**cmd;

	cmd = ft_split(str, ' ');
	if (!ft_strncmp(*cmd, "exit",5))
		ft_exit(cmd[1]);
	pid = fork();
	if (pid < 0)
		ft_put_err("fork failed");
	else if (!pid)
		cmd_do(cmd, envp);
	waitpid(pid, NULL, 0);
}
