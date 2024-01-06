/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fnc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:46:08 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/06 16:51:44 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *s)
{
	t_element	*tmp;

	tmp = s->list[s->top];
	s->list[s->top] = s->list[s->top - 1];
	s->list[s->top - 1] = tmp;
}

void	p(t_stack *from, t_stack *to)
{
	t_element	*tmp;

	tmp = from->list[from->top];
	reset_node(from->list[from->top]);
	from->top--;
	to->top++;
	to->list[to->top] = tmp;
}

void	r(t_stack *s)
{
	t_element	*tmp;
	int			i;

	tmp = s->list[s->top];
	i = s->top;
	while (i > 0)
	{
		s->list[i] = s->list[i - 1];
		i--;
	}
	s->list[0] = tmp;
}

void	rr(t_stack *s)
{
	t_element	*tmp;
	int			i;

	tmp = s->list[0];
	i = 0;
	while (i < s->top)
	{
		s->list[i] = s->list[i + 1];
		i++;
	}
	s->list[s->top] = tmp;
}
