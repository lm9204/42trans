/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:02:09 by yeondcho          #+#    #+#             */
/*   Updated: 2023/10/13 20:35:30 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		countnode;

	if (lst == 0)
		return (0);
	countnode = 1;
	while (lst->next != 0)
	{
		lst = lst->next;
		countnode++;
	}
	return (countnode);
}
