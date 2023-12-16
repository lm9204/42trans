/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:01 by yeondcho          #+#    #+#             */
/*   Updated: 2023/12/16 21:36:14 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_data
{
	int		pid;
	int		size;
	int		p_fd[2];
	char	*io[2];
	char	**envp;
	char	**cmds;
}	t_data;

/* -------------- pipex.c --------------------*/
void	exit_with_err(int errn);
t_data	*init_data(char **arg, char **envp, int size);
void	pipex(t_data *data, char **envp);
void	execute_child(t_data *data, int cmdorder, char **envp);

/* ----------- pipex_utils.c -----------------*/
char	*pathfinder(char **envp, char *cmd);
char	**split_path(char **envp);
char	**split_cmds(char *cmds);
int		count_cmds(char *cmds, const char quotes[]);
char	*ft_cutcmds(const char *cmds, const char quotes[], int *idx);
#endif