/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:33 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 17:28:26 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

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
void		split_cmds(t_stack *stack, char **arg, int *idx);
int			get_stack_size(char **arg);

/* -------------push_swap_fnc.c-------------*/
void		s(t_stack *stack, int isprint);
void		p(t_stack *from, t_stack *to, int isprint);
void		r(t_stack *stack, int isprint);
void		rr(t_stack *stack, int isprint);
void		print_cmd(char name, char *cmd_name);

/* -----------push_swap_utils.c-------------*/
void		err_handler(void);
void		free_str(char **str);
int			check_dup(t_stack *s, char *num, int idx);
int			check_num(char *str);

/* ------------------base.c-----------------*/
char		*base_3(int val);
int			convert_base(char *s, int digit);
long long	power(int x, int y);

/* ------------------list.c-----------------*/
t_element	*create_node(int val);
t_stack		*copy_list(t_stack *a);

/* -----------------radix.c-----------------*/
void		target_push(t_stack *a, t_stack *b, int target, int n);
void		sort_list(t_stack *a, t_stack *b);
void		sort_digit(t_stack *a, t_stack *b, int digit);
void		sort_base_4(t_stack *a, t_stack *b, int digit);
void		sort_except(t_stack *a, t_stack *b);

/* ---------------radix_low.c---------------*/
void		sort_2(t_stack *a);
void		sort_3(t_stack *a);
int			issorted(t_stack *a);
int			get_depth(t_stack *a, int min);
int			get_min(t_stack *a);

/* --------------radix_utils.c--------------*/
void		replace_origin(t_stack *a, t_stack *org);
void		swap_stack(t_stack **a, t_stack **b);
int			get_max_digit(t_stack *a);
int			get_digit(char *base, int digit);

#endif