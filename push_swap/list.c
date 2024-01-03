/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:13:07 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/03 20:28:57 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int val)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->base_4 = -1;
	node->val = val;
	node->next = NULL;
	return (node);
}

void	addlist(t_list **head, t_list *new)
{
	t_list	*ptr;

	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	delnode(t_list **head, int val)
{
	t_list	*prev;
	t_list	*ptr;

	ptr = *head;
	prev = NULL;
	while (ptr)
	{
		if (ptr->val == val)
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

int	push_node(t_list **from, t_list **to, t_list *target)
{
	t_list	*pf;
	t_list	*pt;

	pf = *from;
	pt = *to;
	while (pf)
	{
		if (pf->base_4 == target->base_4)
		{
			addlist(to, target);

			return (1);
		}
		pf = pf->next;
	}
}

int	switch_node(t_list **list, int from, int to)
{

}
