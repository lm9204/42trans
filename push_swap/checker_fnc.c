/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fnc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:46:08 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 19:58:12 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	s(t_stack *s)
{
	int	tmp;

	if (s->top <= 0)
		return ;
	tmp = s->list[s->top];
	s->list[s->top] = s->list[s->top - 1];
	s->list[s->top - 1] = tmp;
	return ;
}

void	p(t_stack *from, t_stack *to)
{
	int	tmp;

	if (from->top == -1)
		return ;
	tmp = from->list[from->top];
	from->list[from->top] = 0;
	from->top--;
	to->top++;
	to->list[to->top] = tmp;
	return ;
}

void	r(t_stack *s)
{
	int	tmp;
	int	i;

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
	return ;
}

void	rr(t_stack *s)
{
	int	tmp;
	int	i;

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
	return ;
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
