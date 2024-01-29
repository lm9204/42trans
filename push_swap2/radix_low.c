/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_low.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:56:45 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/24 17:20:51 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->list[0]->idx < a->list[1]->idx)
		s(a, 1);
}

void	sort_3(t_stack *a)
{
	int	target_num;
	int	target;
	int	i;

	i = a->top;
	target_num = get_min(a);
	while (i >= 0 && !issorted(a))
	{
		target = i - 1;
		if (target < 0)
			target = a->top;
		if (a->list[i]->idx == target_num \
		&& a->list[target]->idx == target_num + 2)
			s(a, 1);
		i--;
	}
	if (a->list[a->top]->idx == target_num + 1)
		rr(a, 1);
	if (a->list[a->top]->idx == target_num + 2)
		r(a, 1);
}

int	issorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->list[i]->val < a->list[i + 1]->val)
			return (0);
		i++;
	}
	return (1);
}

// 0: close top
// 1: close btm
//-1: top
int	get_depth(t_stack *a, int min)
{
	int	depth;
	int	top;
	int	btm;

	depth = 0;
	top = -1;
	while (depth <= a->top)
	{
		if (a->list[depth]->idx == min)
		{
			top = depth;
			btm = a->size - depth;
			break ;
		}
		depth++;
	}
	if (top == a->top)
		return (-1);
	return (top < btm);
}

int	get_min(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = a->top;
	if (min == 0)
		return (0);
	while (i <= a->top)
	{
		if (a->list[i]->idx < min)
			min = a->list[i]->idx;
		i++;
	}
	return (min);
}
