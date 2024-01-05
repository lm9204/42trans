/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:13:07 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/05 11:44:59 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*create_node(int val, int idx)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (node == NULL)
		return (NULL);
	node->base_4 = -1;
	node->idx = idx;
	node->val = val;
	node->next = NULL;
	return (node);
}

int	addlist(t_element **head, t_element *new)
{
	t_element	*ptr;

	ptr = *head;
	if (ptr == NULL)
	{
		*head = new;
		return (1);
	}
	while (ptr && ptr->next)
	{
		if (ptr->idx == new->idx)
			return (0);
		ptr = ptr->next;
	}
	ptr->next = new;
	return (1);
}

void	dellist(t_element **head, int idx)
{
	t_element	*prev;
	t_element	*ptr;

	ptr = *head;
	prev = NULL;
	while (ptr)
	{
		if (ptr->idx == idx)
		{
			if (prev)
				prev->next = ptr->next;
			free(ptr);
			return ;
		}
		prev = ptr;
		ptr = ptr->next;
	}
}

int	push_node(t_element **from, t_element **to, t_element *target)
{
	t_element	*pf;
	t_element	*pt;

	pf = *from;
	pt = *to;
	while (pf)
	{
		if (pf->base_4 == target->base_4)
		{
			addlist(to, target);
			dellist(from, target->idx);
			return (1);
		}
		pf = pf->next;
	}
	return (0);
}

int	switch_node(t_element **list, int from, int to)
{
	t_element	*tmp;
	t_element	*tmp2;
	t_element	*ptr;

	ptr = *list;
	while (ptr && !tmp && !tmp2)
	{
		if (ptr->val == from)
			tmp = ptr;
		else if (ptr->val == to)
			tmp2 = ptr;
		ptr = ptr->next;
	}
	if (tmp && tmp2)
	{
		ptr = tmp;
		tmp = tmp2;
		tmp2 = ptr;
		return (1);
	}
	return (0);
}
