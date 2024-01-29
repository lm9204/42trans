/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:17:05 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/27 11:31:56 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	validate_sort(t_stack *a, t_stack *b)
{
	int	i;

	if (b->top != -1)
		return (0);
	i = a->top;
	while (i > 0)
	{
		if (a->list[i] > a->list[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	validate_inputcmds(t_node **list)
{
	t_node		*ptr;
	const char	*cmds[11] = {"sa", "sb", "ss", "pa", "pb", \
					"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;
	int			max;

	ptr = *list;
	if (ptr == NULL)
		return (1);
	while (ptr)
	{
		i = 0;
		while (i < 11)
		{
			max = ft_strlen(cmds[i]);
			if (ft_strncmp(ptr->cmd, cmds[i], max + 1) == 0)
				break ;
			i++;
		}
		if (i == 11)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	validate_pushswap(t_stack *a, t_stack *b, t_node **list)
{
	t_node	*ptr;

	ptr = *list;
	while (ptr)
	{
		execute_cmds(a, b, ptr->cmd);
		ptr = ptr->next;
	}
	return (validate_sort(a, b));
}

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
		if (s->list[idx + 1] == n)
			return (0);
		i--;
		idx++;
	}
	return (1);
}
