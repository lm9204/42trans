/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:03:19 by yeondcho          #+#    #+#             */
/*   Updated: 2023/10/11 19:20:26 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isset(char c, char const *set);
void	geteachsetlen(char const *s1, char const *set, int *fr, int *ed);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		setlenfr;
	int		setlened;
	int		strlen;
	int		i;

	if (!s1 || !set)
		return (0);
	i = 0;
	strlen = ft_strlen((char *)s1);
	setlenfr = 0;
	setlened = strlen - 1;
	if (setlened < 0)
		setlened = 0;
	geteachsetlen(s1, set, &setlenfr, &setlened);
	strlen -= (strlen - setlened) - 1;
	strlen -= setlenfr - 1;
	result = (char *)malloc(sizeof(char) * (strlen));
	if (result == 0)
		return (0);
	while (setlenfr <= setlened)
		result[i++] = s1[setlenfr++];
	result[i] = 0;
	return (result);
}

void	geteachsetlen(char const *s1, char const *set, int *fr, int *ed)
{
	int	i;

	i = *ed / 2;
	while (s1[*fr] && isset(s1[*fr], set) && *fr <= i)
		(*fr)++;
	while (s1[*ed] && isset(s1[*ed], set) && *ed >= i)
		(*ed)--;
}

int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
