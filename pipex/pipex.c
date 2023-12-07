/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:11 by yeondcho          #+#    #+#             */
/*   Updated: 2023/12/07 22:21:59 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data *data;
	int	fd;
	int	p_fd[2];
	int	status;
	int	i;

	if (access(argv[1], F_OK | R_OK) == -1)
		exit_with_err();
	fd = open(argv[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	pipe(p_fd);
	data = init_data(argv, p_fd, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		data->pid = fork();
		i++;
		if (data->pid == 0)
			pipex(data, i, envp);
		dup2();
	}
	exit(0);
	return (0);
}

t_data	*init_data(char **arg, int fds[2], int size)
{
	t_data	*data;
	int		i;
	int		stridx;

	data = malloc(sizeof(t_data) * 1);
	if (data == NULL)
		exit_with_err();
	data->p_fd = fds;
	data->size = size;
	data->cmds = malloc(sizeof(char *) * (size + 1));
	if (data->cmds == NULL)
		exit_with_err();
	i = 0;
	while (i < size)
	{
		stridx = 0;
		while (arg[i][stridx])
			stridx++;
		data->cmds[i] = malloc(sizeof(char) * (stridx + 1));
		stridx = 0;
		while (arg[i][stridx])
		{
			data->cmds[i][stridx] = arg[i][stridx];
			stridx++;
		}
	}
	return (data);
}

void	exit_with_err(void)
{
	char	*errstr;
	int		strlen;

	strlen = 0;
	errstr = strerror(errno);
	while (errstr[strlen])
		strlen++;
	write(2, errstr, strlen);
	exit(1);
}

void	pipex(t_data *data, int cmdorder, char **envp)
{
	char	*path;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(data->cmds[cmdorder], ' ');
	path = pathfinder(envp);

	execve(path, cmd, envp);
}

char	*pathfinder(char **envp, char *cmd)
{
	char	**res;
	char	*path;
	int		i;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			res = ft_split(*envp, ':');
			break ;
		}
		envp++;
	}
	i = 0;
	while (res[i])
	{
		if (i == 0)
			res[i] += 5;
		path = ft_strjoin(&res[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

