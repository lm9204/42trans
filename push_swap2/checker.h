/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:23:24 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 19:58:20 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int		*list;
	int		top;
	int		size;
}	t_stack;

typedef struct s_node
{
	char			*cmd;
	struct s_node	*next;
}	t_node;

/* -----------------checker.c-------------------*/
void	init_stack(t_stack *stack, char **cmds, int size);
void	getcmds(t_node **head);
void	node_addback(t_node **list, t_node *node);
void	err_handler(void);

/* ---------------checker_utils.c---------------*/
void	execute_cmds(t_stack *a, t_stack *b, char *cmd);
void	assign_cmds(t_stack *stacks[2], char *cmd, int both, int target);
void	split_cmds(t_stack *stack, char **arg, int *idx);
int		insert_stack(t_stack *stack, char **arg, int size);
int		get_stack_size(char **arg);

/* --------------checker_validate.c-------------*/
int		validate_inputcmds(t_node **list);
int		validate_pushswap(t_stack *a, t_stack *b, t_node **list);
int		validate_sort(t_stack *a, t_stack *b);
int		check_num(char *str);
int		check_dup(t_stack *s, char *num, int idx);

/* ---------------checker_fnc.c-----------------*/
void	s(t_stack *stack);
void	p(t_stack *from, t_stack *to);
void	r(t_stack *stack);
void	rr(t_stack *stack);
void	free_str(char **str);

#endif