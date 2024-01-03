/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:23:24 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/03 19:44:24 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include "libft/libft.h"
# include "stack.h"

typedef struct s_node
{
	char			*cmd;
	struct s_node	*next;
}	t_node;

/* -----------------checker.c .-----------------*/
void	init_stack(t_stack *stack, char *cmds, int size);
void	getcmds(t_node **head);
int		validate_inputcmds(t_node **list);
int		validate_pushswap(t_stack *a, t_stack *b, t_node **list);
int		validate_sort(t_stack *a, t_stack *b);

/* ---------------push_swap_fnc.c---------------*/
void	s(t_stack *stack);
void	p(t_stack *from, t_stack *to);
void	r(t_stack *stack);
void	rr(t_stack *stack);

/* ---------------checker_utils.c---------------*/
void	execute_cmds(t_stack *a, t_stack *b, char *cmd);
void	err_handler(void);
int		get_stack_size(char *arg);
int		insert_stack(t_stack *stack, char *stack_str);
int		check_num(char *str);
void	both_stack(t_stack *s1, t_stack *s2, void (*f)(t_stack *));

/* -------------------node.c-------------------*/
void	node_addback(t_node **list, t_node *node);

void	test_print(t_stack *s);
#endif