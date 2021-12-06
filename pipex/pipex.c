/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:59:21 by decordel          #+#    #+#             */
/*   Updated: 2021/12/02 21:18:58 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

static void	cmd_do(t_pip *pip, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[pip->i], ' ');
	if (access(*cmd, F_OK) == 0)
		path = *cmd;
	else
		path = path_command(*cmd, envp);
	if (path)
		execve(path, cmd, envp);
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(cmd[0], 2);
	split_free(cmd);
	put_error(cmd[0]);
}

static void	pipex(t_pip *pip, int argc, char **argv, char **envp)
{
	while (pip->i + 2 != argc)
	{
		if (pipe(pip->fd) < 0)
			put_error("pipex: pipe failed");
		pip->pid = fork();
		if (pip->pid < 0)
			put_error("pipex: fork failed");
		if (!pip->pid)
		{
			dup2(pip->fd[1], 1);
			close(pip->fd[0]);
			cmd_do(pip, argv, envp);
		}
		waitpid(pip->pid, NULL, 0);
		dup2(pip->fd[0], 0);
		close(pip->fd[1]);
		pip->i++;
	}
}

static void	read_here_doc(char *lim)
{
	t_pip	pip;

	if (pipe(pip.fd) < 0)
		put_error("pipex: pipe failed");
	pip.pid = fork();
	if (pip.pid < 0)
		put_error("pipex: fork failed");
	if (!pip.pid)
	{
		close(pip.fd[0]);
		read_gnl(lim, pip);
	}
	else
	{
		waitpid(pip.pid, NULL, 0);
		close(pip.fd[1]);
		dup2(pip.fd[0], 0);
	}
}

static void	open_in_out(t_pip *pip, int argc, char **argv, char **envp)
{
	int	in;
	int	out;

	if (pip->i == 3)
		read_here_doc(argv[2]);
	else
	{
		in = open(argv[1], O_RDONLY);
		if (in < 0)
			put_error("pipex: open error");
		dup2(in, 0);
	}
	pipex(pip, argc, argv, envp);
	out = open(argv[argc - 1], O_WRONLY | O_CREAT | pip->k, 0644);
	if (out < 0)
		put_error("pipex: open error");
	dup2(out, 1);
	cmd_do(pip, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pip;

	if (argc < 5)
		put_error("pipex: ./pipex file1 cmd1 cmd2 file2");
	pip.i = 2;
	pip.k = O_TRUNC;
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		if (argc < 6)
			put_error("pipex: ./pipex here_doc lim f1 c1 ... cN f2");
		pip.k = O_APPEND;
		pip.i = 3;
	}
	open_in_out(&pip, argc, argv, envp);
	return (0);
}
