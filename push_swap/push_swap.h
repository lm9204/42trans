/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:33 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/17 21:57:56 by yeondcho         ###   ########.fr       */
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
	char	*base_3;
	int		val;
	int		idx;
}	t_element;

//replace : idx : val로  치환한 값 
typedef struct s_stack
{
	t_element	**list;
	char		name;
	int			top;
	int			size;
}	t_stack;

/* ---------------push_swap.c---------------*/
void		init_list(t_stack *s, char **arg, int size, char name);
void		init_idx(t_stack *s);
int			get_stack_size(char **arg);
int			insert_stack(t_stack *stack, char *argv);

/* -------------push_swap_fnc.c-------------*/
void		s(t_stack *stack, int isprint);
void		p(t_stack *from, t_stack *to, int isprint);
void		r(t_stack *stack, int isprint);
void		rr(t_stack *stack, int isprint);
void		print_cmd(char name, char *cmd_name);

void		err_handler(void);
int			check_num(char *str);
int			check_dup(t_stack *s, char *num, int idx);
/* ------------------base.c-----------------*/
char		*base_3(int val);
int			convert_base(char *s, int digit);
long long	power(int x, int y);
/* ------------------list.c-----------------*/
t_element	*create_node(int val);
t_stack		*copy_list(t_stack *a);
void		reset_node(t_element *node);
/* -----------------radix.c-----------------*/
void		sort_list(t_stack *a, t_stack *b);
void		sort_digit(t_stack *a, t_stack *b, int digit);
void		sort_base_4(t_stack *a, t_stack *b, int digit);
void		swap_stack(t_stack **a, t_stack **b);
void		replace_origin(t_stack *a, t_stack *org);
int			get_max_digit(t_stack *a);
int			get_digit(char *base, int digit);
void		print_list(t_stack *s);

#endif