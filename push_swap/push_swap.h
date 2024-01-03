/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:33 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/03 20:29:12 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "stack.h"

typedef struct s_list
{
	long long		base_4;
	int				val;
	struct s_list	*next;
}	t_list;

/* ---------------push_swap.c---------------*/
void	init_stack(t_stack *stack, int size);
int		get_stack_size(char *stack);
int		insert_stack(t_stack *stack, char *argv);

/* -------------push_swap_fnc.c-------------*/
void	s(t_stack *stack);
void	p(t_stack *from, t_stack *to);
void	r(t_stack *stack);
void	rr(t_stack *stack);

void	err_handler(void);
int		check_num(char *str);
/* ------------------base.c-----------------*/
void	convert_4(t_list **list);
void	convert_10(t_list **list);
/* ------------------list.c-----------------*/
t_list	*create_node(int val);
void	addlist(t_list **head, t_list *new);
void	delnode(t_list **head, int val);
int		push_node(t_list **from, t_list **to, t_list *target);
int		switch_node(t_list **list, int from, int to);

void	test_print(t_stack *s);

#endif