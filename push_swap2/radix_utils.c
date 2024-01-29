/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:13:17 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/27 11:23:33 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_origin(t_stack *a, t_stack *o)
{
	char	*tmp;
	int		idx;

	idx = o->top;
	while (idx >= 0)
	{
		tmp = ft_strdup(a->list[o->top - o->list[idx]->idx]->base_3);
		free(o->list[idx]->base_3);
		o->list[idx]->base_3 = tmp;
		idx--;
	}
}

void	swap_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	get_max_digit(t_stack *a)
{
	char	*tmp;
	int		i;
	int		max;
	int		length;

	i = a->top;
	max = 0;
	while (i >= 0)
	{
		if (a->list[i]->idx > max)
			max = a->list[i]->idx;
		i--;
	}
	tmp = base_3(max);
	length = ft_strlen(tmp);
	free(tmp);
	if (length % 2 == 1)
		length++;
	return (length);
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
