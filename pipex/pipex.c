/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:11 by yeondcho          #+#    #+#             */
/*   Updated: 2023/12/16 19:58:30 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	int		exit_code;
	int		size;
	int		ret;
	int		i;

	if (argc < 5)
		exit_with_err(22);
	size = argc - 3;
	data = init_data(argv + 1, envp, size);
	ret = 0;
	pipex(data, envp);
	exit_code = 0;
	i = size;
	while (i > 0)
	{
		if (wait(&ret) == data->pid)
		{
			if (WIFEXITED(ret))
				exit_code = WEXITSTATUS(ret);
		}
		//if (waitpid(data->pid, ret, WNOHANG) != 0)
		i--;
	}
	exit(exit_code);
}

void	pipex(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (i < data->size - 1)
			pipe(data->p_fd);
		data->pid = fork();
		if (data->pid == 0)
			execute_child(data, i, envp);
		//dup2(data->p_fd[0], STDIN_FILENO);
		i++;
	}
	close(data->p_fd[0]);
	close(data->p_fd[1]);

}

t_data	*init_data(char **arg, char **envp, int size)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data) * 1);
	// if (data == NULL)
	// 	exit_with_err("init_data");
	data->io[0] = arg[0];
	data->io[1] = arg[size + 1];
	data->size = size;
	data->envp = split_path(envp);
	data->cmds = malloc(sizeof(char *) * (size + 1));
	// if (data->cmds == NULL)
		// exit_with_err("init_data");
	i = 0;
	arg++;
	while (i < size)
	{
		data->cmds[i] = ft_strdup(arg[i]);
		i++;
	}
	data->cmds[i] = NULL;
	return (data);
}

void	exit_with_err(int errn)
{
	char	*res;

	res = NULL;
	if (errn == 127)
		res = "command not found";
	else if (errn)
		res = strerror(errn);
	else if (errno)
		res = strerror(errno);
	if (res != NULL)
		ft_putendl_fd(res, 2);
	if (errn)
		exit(errn);
	exit(1);
}

void	execute_child(t_data *data, int cmdorder, char **envp)
{
	char	*path;
	char	**arg;
	int		fd;

	dup2(data->p_fd[1], STDOUT_FILENO);
	dup2(data->p_fd[0], STDIN_FILENO);
	if (cmdorder == 0)
	{
		fd = open(data->io[0], O_RDONLY);
		if (fd == -1)
			exit_with_err(0);
		dup2(fd, STDIN_FILENO);
		close(data->p_fd[0]);
		close(data->p_fd[1]);
		close(fd);
	}
	if (cmdorder == data->size - 1)
	{
		fd = open(data->io[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fd == -1)
			exit_with_err(0);
		dup2(fd, STDOUT_FILENO);
		close(data->p_fd[0]);
		close(data->p_fd[1]);
		close(fd);
	}
	arg = split_cmds(data->cmds[cmdorder]);
	path = pathfinder(data->envp, arg[0]);
	if (path == NULL)
		exit_with_err(127);
	if (execve(path, arg, envp) == -1)
		exit_with_err(126);
}
