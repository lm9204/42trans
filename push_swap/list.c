/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:13:07 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/06 17:47:37 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*create_node(int val, int idx)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (node == NULL)
		return (NULL);
	node->base_4 = base_4(val);
	node->idx = idx;
	node->val = val;
	return (node);
}

void	reset_node(t_element *node)
{
	node->base_4 = -1;
	node->idx = -1;
	node->val = -1;
}

// int	push_node(t_element **from, t_element **to, t_element *target)
// {
// 	t_element	*pf;
// 	t_element	*pt;

// 	pf = *from;
// 	pt = *to;
// 	while (pf)
// 	{
// 		if (pf->base_4 == target->base_4)
// 		{
// 			addlist(to, target);
// 			dellist(from, target->idx);
// 			return (1);
// 		}
// 		pf = pf->next;
// 	}
// 	return (0);
// }

// int	switch_node(t_element **list, int from, int to)
// {
// 	t_element	*tmp;
// 	t_element	*tmp2;
// 	t_element	*ptr;

// 	ptr = *list;
// 	while (ptr && !tmp && !tmp2)
// 	{
// 		if (ptr->val == from)
// 			tmp = ptr;
// 		else if (ptr->val == to)
// 			tmp2 = ptr;
// 		ptr = ptr->next;
// 	}
// 	if (tmp && tmp2)
// 	{
// 		ptr = tmp;
// 		tmp = tmp2;
// 		tmp2 = ptr;
// 		return (1);
// 	}
// 	return (0);
// }
