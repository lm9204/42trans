/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:53:59 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 19:11:43 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort b from a by digit
//digit = 자릿수
//digit_n = 해당 노드에 digit(자릿수)에 있는 수의 값
void	sort_list(t_stack *a, t_stack *b)
{
	int		digit;
	int		max_digit;
	int		i;

	digit = 1;
	max_digit = get_max_digit(a);
	if (max_digit % 2 == 1)
		max_digit++;
	if (a->size <= 5)
		sort_except(a, b);
	i = 0;
	while (max_digit-- > 0 && a->size > 5)
	{
		if (3 * power(3, i) < a->size && a->size <= 4 * power(3, i) \
		&& i % 2 != 0)
		{
			sort_base_4(a, b, digit);
			break ;
		}
		else
			sort_digit(a, b, digit++);
		swap_stack(&a, &b);
		i++;
	}
}

void	sort_base_4(t_stack *a, t_stack *b, int digit)
{
	int		target;
	int		i;
	int		n;

	target = 0;
	while (target < 4)
	{
		i = 0;
		while (i < a->size && a->top != -1)
		{
			n = convert_base(a->list[a->top]->base_3, digit);
			target_push(a, b, target, n);
			i++;
		}
		target += 2;
	}
}

void	sort_digit(t_stack *a, t_stack *b, int digit)
{
	int	isprint;
	int	n;
	int	i;

	i = 0;
	isprint = 0;
	if (a->name == 'o' || b->name == 'o')
		isprint = 1;
	while (i < a->size)
	{
		n = get_digit(a->list[a->top]->base_3, digit);
		target_push(a, b, 0, n);
		i++;
	}
	while (a->top != -1)
		p(a, b, isprint);
}

void	sort_except(t_stack *a, t_stack *b)
{
	int	i;
	int	min;

	if (a->top == 1)
		sort_2(a);
	else if (a->top == 2)
		sort_3(a);
	else
	{
		i = a->top;
		min = get_min(a);
		if (issorted(a))
			return ;
		while (i >= 0 && a->list[a->top]->idx != min)
		{
			if (get_depth(a, min) == 1)
				rr(a, 1);
			else if (get_depth (a, min) == 0)
				r(a, 1);
			i++;
		}
		p(a, b, 1);
		sort_except(a, b);
		p(b, a, 1);
	}
}

void	target_push(t_stack *a, t_stack *b, int target, int n)
{
	int	isprint;

	isprint = 0;
	if (a->name == 'o' || b->name == 'o')
		isprint = 1;
	if (n == target)
		p(a, b, isprint);
	else if (n == target + 1)
	{
		p(a, b, isprint);
		r(b, isprint);
	}
	else
		r(a, isprint);
}
