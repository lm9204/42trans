/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:21:28 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/03 19:44:09 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_cmds(t_stack *a, t_stack *b, char *cmd)
{
	t_stack	*stacks[2];
	int		target;
	int		both;
	int		len;

	both = 0;
	stacks[A] = a;
	stacks[B] = b;
	len = ft_strlen(cmd);
	if (cmd[len - 1] == 'a')
		target = A;
	else if (cmd[len - 1] == 'b')
		target = B;
	else if (cmd[len - 1] == 's' || cmd[len - 1] == 'r')
		both = 1;
	else
		err_handler();
	if (cmd[0] == 's' && !both)
		s(stacks[target]);
	else if (cmd[0] == 'p' && !both)
		p(stacks[target ^ 1], stacks[target]);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && !both)
		rr(stacks[target]);
	else if (cmd[0] == 'r' && !both)
		r(stacks[target]);
	else if (cmd[0] == 's' && both)
		both_stack(stacks[A], stacks[B], s);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && both)
		both_stack(stacks[A], stacks[B], rr);
}

void	both_stack(t_stack *s1, t_stack *s2, void (*f)(t_stack *))
{
	f(s1);
	f(s2);
}

int	insert_stack(t_stack *stack, char *stack_str)
{
	char	**data;
	int		i;

	data = ft_split(stack_str, ' ');
	if (data == NULL)
		return (-1);
	i = stack->size - 1;
	while (i >= 0)
	{
		if (!check_num(data[stack->size - i - 1]))
			err_handler();
		stack->stack[i] = ft_atoi(data[stack->size - i - 1]);
		stack->top++;
		i--;
	}
	return (1);
}

void	err_handler(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	get_stack_size(char *arg)
{
	int	count;

	count = 0;
	while (*arg)
	{
		if (*arg != ' ')
			count++;
		arg++;
	}
	return (count);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
