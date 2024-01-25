/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:13:07 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 17:22:59 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*create_node(int val)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (node == NULL)
		return (NULL);
	node->base_3 = NULL;
	node->idx = -1;
	node->val = val;
	return (node);
}

t_stack	*copy_list(t_stack *a)
{
	t_stack	*ptr;
	int		i;

	ptr = malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->name = 'o';
	ptr->size = a->size;
	ptr->top = a->top;
	ptr->list = malloc(sizeof(t_element *) * (a->size));
	if (ptr->list == NULL)
		return (NULL);
	i = 0;
	while (i < a->size)
	{
		ptr->list[i] = malloc(sizeof(t_element));
		if (ptr->list[i] == NULL)
			return (NULL);
		ptr->list[i]->val = a->list[i]->val;
		if (a->list[i]->base_3 != NULL)
			ptr->list[i]->base_3 = ft_strdup(a->list[i]->base_3);
		ptr->list[i]->idx = a->list[i]->idx;
		i++;
	}
	return (ptr);
}
