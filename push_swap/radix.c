/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:53:59 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/05 17:41:28 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort b from a by digit
//digit = 자릿수
//digit_n = 해당 노드에 digit(자릿수)에 있는 수의 값
void	sort_list(t_element **a, t_element **b)
{
	long long	max_num;
	long long	digit;

	digit = 1;
	max_num = 2030201;
	while (digit < max_num)
	{
		
		digit *= 10;
	}

}



void	sort_digit(t_element **a, t_element **b, long long digit)
{
	t_element	*ap;
	int			digit_n;
	int			target;

	ap = *a;
	target = 0;
	while (ap)
	{
		digit_n = (ap->base_4 / digit) % 10;

		ap = ap->next;
	}
	ap = *a;
	target += 2;
	while (ap)
	{

		ap = ap->next;
	}
}

int	get_digit(t_element *node, int digit)
{
	int	digit_n;
	
	digit_n = (node->base_4 / digit) % 10;
	return (digit_n);
}

//target_digit : 0 1 2 3
//dir : 1 : bigger top
//		0 : bigger btm
//		-1: no target
int	get_direction(t_element **a, int target_digit, int digit)
{
	t_element	*ptr;
	int			top_depth;
	int			btm_depth;
	int			depth;

	ptr = *a;
	depth = 0;
	top_depth = -1;
	btm_depth = -1;
	while (ptr)
	{
		if (get_digit(ptr, digit) == target_digit \
		|| get_digit(ptr, digit) == target_digit + 1)
		{
			if (top_depth == 0)
				top_depth = depth;
			else
				btm_depth = depth;
		}
		depth++;
		ptr = ptr->next;
	}
	btm_depth = depth - btm_depth;
	if (top_depth == -1 && btm_depth == -1)
		return (-1);
	return (top_depth > btm_depth);
}
