/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:45:47 by yeondcho          #+#    #+#             */
/*   Updated: 2023/12/16 19:45:28 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pathfinder(char **envp, char *cmd)
{
	char	*path;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	if (ft_strchr(cmd, '/') != 0)
		return (0);
	i = 0;
	while (envp && envp[i])
	{
		path = ft_strjoin(envp[i++], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

char	**split_path(char **envp)
{
	char	**res;
	int		i;

	res = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			res = ft_split(*envp, ':');
			break ;
		}
		envp++;
	}
	// if (res == NULL)
	// 	exit_with_err("split_path");
	i = 0;
	res[0] += 5;
	while (res[i])
	{
		res[i] = ft_strjoin(res[i], "/");
		i++;
	}
	return (res);
}

char	**split_cmds(char *cmds)
{
	const char	quotes[2] = {'"', '\''};
	char		**res;
	int			size;
	int			idx;
	int			i;

	size = count_cmds(cmds, quotes);
	res = malloc(sizeof(char *) * (size + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	idx = 0;
	while (i < size)
	{
		res[i] = ft_cutcmds(cmds, quotes, &idx);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	ft_isquotes(char c, const char quotes[2])
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (c == quotes[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cutcmds(const char *cmds, const char quotes[2], int *idx)
{
	char	*word;
	int		len;
	int		isquotes;

	len = 0;
	isquotes = 0;
	if (ft_isquotes(cmds[len + *idx], quotes))
	{
		(*idx)++;
		isquotes = 1;
		while (cmds[len + *idx] && !ft_isquotes(cmds[len + *idx], quotes))
			len++;
	}
	else
		while (cmds[len + *idx] && cmds[len + *idx] != ' ')
			len++;
	word = ft_allocword(&cmds[*idx], len);
	if (isquotes)
		(*idx)++;
	if (word == NULL)
		return (NULL);
	while (cmds[len + *idx] && cmds[len + *idx] == ' ')
		(*idx)++;
	*idx += len;
	return (word);
}

int	count_cmds(char *cmds, const char quotes[])
{
	int			count;
	int			isquotes;
	int			isword;

	count = 0;
	isword = 0;
	isquotes = 0;
	while (*cmds)
	{
		if (isquotes && (*cmds == quotes[0] || *cmds == quotes[1]))
			isquotes = 0;
		else if (!isquotes && (*cmds == quotes[0] || *cmds == quotes[1]))
			isquotes = 1;
		if (isquotes && cmds++)
			continue ;
		if (!isword && *cmds != ' ')
		{
			count++;
			isword = 1;
		}
		if (isword && (*cmds == ' '))
			isword = 0;
		cmds++;
	}
	return (count);
}
