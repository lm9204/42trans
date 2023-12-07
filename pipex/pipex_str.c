/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:46:04 by yeondcho          #+#    #+#             */
/*   Updated: 2023/12/07 21:50:04 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		search_idx;
	int		wordcount;

	search_idx = 0;
	wordcount = ft_countwords(s, c);
	result = (char **)ft_calloc(8, wordcount + 1);
	if (result == NULL)
		return (NULL);
	while (s[search_idx] && s[search_idx] == c)
		search_idx++;
	i = -1;
	while (++i < wordcount)
	{
		result[i] = ft_cutword(s, c, &search_idx);
		if (result[i] == NULL)
		{
			while (i-- > 0)
				free(result[i]);
			free(result);
			return (NULL);
		}
	}
	return (result);
}

char	*ft_cutword(const char *s, char c, int *search_idx)
{
	char	*word;
	int		wordlen;

	wordlen = 0;
	while (s[wordlen + *search_idx] && s[wordlen + *search_idx] != c)
		wordlen++;
	word = ft_allocword(&s[*search_idx], wordlen);
	if (word == NULL)
		return (NULL);
	while (s[wordlen + *search_idx] && s[wordlen + *search_idx] == c)
		(*search_idx)++;
	*search_idx += wordlen;
	return (word);
}

char	*ft_allocword(const char *s, int size)
{
	char	*word;
	int		i;

	word = (char *)ft_calloc(1, size + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

int	ft_countwords(const char *s, char c)
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
			isword = 0;
		s++;
	}
	return (count);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}