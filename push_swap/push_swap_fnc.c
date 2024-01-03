/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fnc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:46:08 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/03 19:40:45 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	s(t_stack *s)
{
	int	tmp;

	tmp = s->stack[s->top];
	s->stack[s->top] = s->stack[s->top - 1];
	s->stack[s->top - 1] = tmp;
}

void	p(t_stack *from, t_stack *to)
{
	int	tmp;

	tmp = from->stack[from->top];
	from->stack[from->top] = 0;
	from->top--;
	to->top++;
	to->stack[to->top] = tmp;
}

void	r(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->stack[s->top];
	i = s->top;
	while (i > 0)
	{
		s->stack[i] = s->stack[i - 1];
		i--;
	}
	s->stack[0] = tmp;
}

void	rr(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->stack[0];
	i = 0;
	while (i < s->top)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[s->top] = tmp;
}
