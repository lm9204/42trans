/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fnc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:46:08 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 17:41:48 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *s, int isprint)
{
	t_element	*tmp;

	if (s->top <= 0)
		return ;
	tmp = s->list[s->top];
	s->list[s->top] = s->list[s->top - 1];
	s->list[s->top - 1] = tmp;
	if (isprint)
		print_cmd(s->name, "s");
	return ;
}

void	p(t_stack *from, t_stack *to, int isprint)
{
	t_element	*tmp;

	if (from->top == -1)
		return ;
	tmp = from->list[from->top];
	from->list[from->top] = 0;
	from->top--;
	to->top++;
	to->list[to->top] = tmp;
	if (isprint)
		print_cmd(to->name, "p");
	return ;
}

void	r(t_stack *s, int isprint)
{
	t_element	*tmp;
	int			i;

	if (s->top <= 0)
		return ;
	tmp = s->list[s->top];
	i = s->top;
	while (i > 0)
	{
		s->list[i] = s->list[i - 1];
		i--;
	}
	s->list[i] = tmp;
	if (isprint)
		print_cmd(s->name, "r");
	return ;
}

void	rr(t_stack *s, int isprint)
{
	t_element	*tmp;
	int			i;

	if (s->top <= 0)
		return ;
	tmp = s->list[0];
	i = 0;
	while (i < s->top)
	{
		s->list[i] = s->list[i + 1];
		i++;
	}
	s->list[i] = tmp;
	if (isprint)
		print_cmd(s->name, "rr");
	return ;
}

void	print_cmd(char name, char *cmd_name)
{
	write(1, cmd_name, ft_strlen(cmd_name));
	if (name == 'o')
		write(1, "a", 1);
	else
		write(1, &name, 1);
	write(1, "\n", 1);
}
