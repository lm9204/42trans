/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:32:35 by yeondcho          #+#    #+#             */
/*   Updated: 2023/10/12 14:35:50 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*tmp;

	nlst = 0;
	while (lst != 0)
	{
		if (f(lst->content))
		{
			tmp = (t_list *)malloc(sizeof(t_list));
			tmp->content = lst->content;
			if (nlst)
				nlst->next = tmp;
			nlst = tmp;
			lst = lst->next;
		}
		else
		{
			del(lst->content);
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
	}
	return (nlst);
}
