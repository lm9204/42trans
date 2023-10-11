/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:04:22 by yeondcho          #+#    #+#             */
/*   Updated: 2023/10/11 17:29:41 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		strlen;
	int		i;

	i = 0;
	strlen = ft_strlen((char *)s1);
	strlen += ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (strlen + 1));
	if (result == 0)
		return (0);
	while (*s1 && i < strlen)
	{
		result[i++] = *s1++;
	}
	while (*s2 && i < strlen)
		result[i++] = *s2++;
	result[i] = 0;
	return (result);
}
