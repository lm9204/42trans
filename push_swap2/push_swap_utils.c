/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:13:56 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 17:29:01 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str)
{
	char	*cvt_overflow;
	int		i;
	int		num;

	i = 0;
	if (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+'))
		err_handler();
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
			err_handler();
		i++;
	}
	num = ft_atoi(str);
	cvt_overflow = ft_itoa(num);
	if (ft_strncmp(str, cvt_overflow, ft_strlen(str) + 1) != 0)
		err_handler();
	free(cvt_overflow);
	return (1);
}

void	err_handler(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_dup(t_stack *s, char *num, int idx)
{
	int	i;
	int	n;

	if (idx < 0)
		return (1);
	i = s->top;
	n = ft_atoi(num);
	while (i >= 0)
	{
		if (s->list[idx + 1]->val == n)
			return (0);
		i--;
		idx++;
	}
	return (1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
