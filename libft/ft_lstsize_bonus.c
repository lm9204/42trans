/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:02:09 by yeondcho          #+#    #+#             */
/*   Updated: 2023/10/12 14:35:59 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		countnode;

	countnode = 0;
	ptr = lst;
	while (ptr != 0)
	{
		countnode++;
		ptr = ptr->next;
	}
	return (countnode);
}
