/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:51:30 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/18 14:24:46 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*base_3(int val)
{
	char	*res;
	char	tmp[21];
	int		i;
	int		size;

	size = 0;
	if (val == 0)
		tmp[size++] = '0';
	while (val != 0)
	{
		tmp[size] = val % 3 + '0';
		val /= 3;
		size++;
	}
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	res[size] = 0;
	i = 0;
	while (i < size)
	{
		res[i] = tmp[size - i - 1];
		i++;
	}
	return (res);
}

int	convert_base(char *s, int digit)
{
	int	res;
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (i < 2)
	{
		if (i != 0)
			n += get_digit(s, digit + i) * i * 10;
		else
			n += get_digit(s, digit + i);
		i++;
	}
	i = 0;
	res = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		res += (n % 10) * power(3, i);
		n /= 10;
		i++;
	}
	return (res);
}

long long	power(int x, int y)
{
	long long	n;

	if (y == 0)
		return (1);
	n = 1;
	while (y > 0)
	{
		n *= x;
		y--;
	}
	return (n);
}
