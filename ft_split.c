/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:37:25 by yeondcho          #+#    #+#             */
/*   Updated: 2023/10/11 19:37:52 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

static int		ft_countwords(char const *s, char c);
static char		*ft_splitword(char const *s, int size);
static char		*ft_cutword(char const *s, char c, int *schidx);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		wordcount;
	int		schidx;
	int		i;

	i = 0;
	schidx = 0;
	wordcount = ft_countwords(s, c);
	result = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (result == 0)
		return (0);
	while (s[schidx] && s[schidx] == c)
		schidx++;
	while (i < wordcount)
		result[i++] = ft_cutword(s, c, &schidx);
	result[i] = 0;
	return (result);
}

static char	*ft_cutword(char const *s, char c, int *schidx)
{
	char	*word;
	int		wordlen;

	wordlen = 0;
	while (s[wordlen + *schidx] && s[wordlen + *schidx] != c)
		wordlen++;
	word = ft_splitword(&s[*schidx], wordlen);
	while (s[wordlen + *schidx] && s[wordlen + *schidx] == c)
		(*schidx)++;
	*schidx += wordlen;
	return (word);
}

static char	*ft_splitword(char const *s, int size)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (word == 0)
		return (0);
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static int	ft_countwords(char const *s, char c)
{
	int	isword;
	int	count;

	isword = 0;
	count = 0;
	while (*s)
	{
		if (!isword && *s != c)
		{
			isword = 1;
			count++;
		}
		if (isword && *s == c)
		{
			isword = 0;
		}
		s++;
	}
	return (count);
}
