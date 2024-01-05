/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:33 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/05 19:16:46 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct s_element
{
	int	val;
}	t_element;

typedef struct s_stack
{
	t_element	*stack;
	int			top;
	int			size;
}	t_stack;

/* ---------------push_swap.c---------------*/
void		init_list(t_element **list, char **arg, int size);
int			get_stack_size(char *stack);
int			insert_stack(t_stack *stack, char *argv);

/* -------------push_swap_fnc.c-------------*/
void		s(t_stack *stack);
void		p(t_stack *from, t_stack *to);
void		r(t_stack *stack);
void		rr(t_stack *stack);

void		err_handler(void);
int			check_num(char *str);
/* ------------------base.c-----------------*/
long long	base_4(int val);
void		convert_4(t_element **list);
/* ------------------list.c-----------------*/
t_element	*create_node(int val, int idx);
void		dellist(t_element **head, int val);
int			addlist(t_element **head, t_element *new);
int			push_node(t_element **from, t_element **to, t_element *target);
int			switch_node(t_element **list, int from, int to);

void		print_list(t_element **list);

#endif