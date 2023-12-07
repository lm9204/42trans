/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:01 by yeondcho          #+#    #+#             */
/*   Updated: 2023/12/07 22:16:41 by yeondcho         ###   ########.fr       */
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

typedef struct s_data
{
	int		pid;
	int		size;
	int		*p_fd;
	char	**cmds;
}	t_data;

/* ------------ pipex_str.c ------------------*/
/* -------------- pipex.c --------------------*/
void	exit_with_err(void);
t_data	*init_data(char **arg, int fds[2], int size);
void	pipex(t_data *data, int cmdorder, char **envp);
char	*pathfinder(char **envp, char *cmd);

/* ------------ pipex_str.c ------------------*/
char	**ft_split(const char *s, char c);
char	*ft_cutword(const char *s, char c, int *search_idx);
char	*ft_allocword(const char *s, int size);
int		ft_countwords(const char *s, char c);
int		ft_strlen(const char *s);

#endif