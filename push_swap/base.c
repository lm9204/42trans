/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:51:30 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/06 13:17:20 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_4(t_element **list)
{
	t_element		*ptr;

	ptr = *list;
	while (ptr)
	{
		ptr->base_4 = base_4(ptr->idx);
		ptr = ptr->next;
	}
}

long long	power(int n, int power)
{
	long long	res;
	int			i;

	i = 0;
	res = n;
	if (power < 0)
		return (1);
	while (i < power)
	{
		res *= 10;
		i++;
	}
	return (res);
}

long long	base_4(int val)
{
	long long	n;
	int			i;

	if (val == 0)
		return (0);
	i = 0;
	n = 0;
	while (val != 0)
	{
		n += (val % 4) * power(10, i - 1);
		val /= 4;
		i++;
	}
	return (n);
}
