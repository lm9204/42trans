/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:53:59 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/17 22:35:09 by yeondcho         ###   ########.fr       */
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
	int		flag;

	digit = 1;
	flag = 0;
	max_digit = get_max_digit(a);
	i = 0;
	while (max_digit > 0)
	{
		if (3 * power(3, i) < a->size && a->size <= 4 * power(3, i))
		{
			sort_base_4(a, b, digit);
			return ;
		}
		else
			sort_digit(a, b, digit);
		swap_stack(&a, &b);
		i++;
		max_digit--;
		digit++;
	}
}

void	sort_base_4(t_stack *a, t_stack *b, int digit)
{
	int		target;
	int		isprint;
	int		i;
	int		j;
	int		n;

	target = 0;
	isprint = 0;
	if (a->name == 'o' || b->name == 'o')
		isprint = 1;
	j = 0;
	while (j < 2)
	{
		i = 0;
		while (i < a->size && a->top != -1)
		{
			n = convert_base(a->list[a->top]->base_3, digit);
			if (n == target)
				p(a, b, isprint);
			else if (n == target + 1)
			{
				p(a, b, isprint);
				r(b, isprint);
			}
			else
				r(a, isprint);
			i++;
		}
		target = 2;
		j++;
	}
}

void	sort_digit(t_stack *a, t_stack *b, int digit)
{
	int		n;
	int		i;
	int		isprint;

	isprint = 0;
	if (a->name == 'o' || b->name == 'o')
		isprint = 1;
	i = 0;
	while (i < a->size && a->top != -1)
	{
		n = get_digit(a->list[a->top]->base_3, digit);
		if (n == 0)
			p(a, b, isprint);
		else if (n == 1)
		{
			p(a, b, isprint);
			r(b, isprint);
		}
		else
			r(a, isprint);
		i++;
	}
	while (a->top != -1)
		p(a, b, isprint);
}

void	swap_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	replace_origin(t_stack *a, t_stack *o)
{
	char	*tmp;
	int		idx;

	idx = o->top;
	while (idx >= 0)
	{
		tmp = ft_strdup(a->list[o->top - o->list[idx]->idx]->base_3);
		o->list[idx]->base_3 = tmp;
		idx--;
	}
}

int	get_max_digit(t_stack *a)
{
	int	i;
	int	max;

	i = a->top;
	max = 0;
	while (i >= 0)
	{
		if (a->list[i]->idx > max)
			max = a->list[i]->idx;
		i--;
	}
	return (ft_strlen(base_3(max)));
}

int	get_digit(char *base, int digit)
{
	int	digit_n;
	int	length;

	length = ft_strlen(base);
	digit_n = length - digit;
	if (digit_n < 0)
		return (0);
	return (base[digit_n] - 48);
}
