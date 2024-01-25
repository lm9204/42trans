/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:21:28 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 21:50:15 by yeondcho         ###   ########.fr       */
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
	target = 0;
	stacks[0] = a;
	stacks[1] = b;
	len = ft_strlen(cmd);
	if (cmd[len - 1] == 'a')
		target = 0;
	else if (cmd[len - 1] == 'b')
		target = 1;
	else if (cmd[len - 1] == 's' || cmd[len - 1] == 'r')
		both = 1;
	else
		err_handler();
	assign_cmds(stacks, cmd, both, target);
}

void	assign_cmds(t_stack *stacks[2], char *cmd, int both, int target)
{
	if (cmd[0] == 's' && !both)
		s(stacks[target]);
	else if (cmd[0] == 'p' && !both)
		p(stacks[target ^ 1], stacks[target]);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && !both)
		rr(stacks[target]);
	else if (cmd[0] == 'r' && !both)
		r(stacks[target]);
	else if (cmd[0] == 's' && both)
	{
		s(stacks[0]);
		s(stacks[1]);
	}
	else if (cmd[0] == 'r' && cmd[1] == 'r' && both)
	{
		r(stacks[0]);
		r(stacks[1]);
	}
}

int	insert_stack(t_stack *stack, char **arg, int size)
{
	char		**tmp;
	int			idx;
	int			i;

	idx = size - 1;
	stack->top = -1;
	if (size == 0)
		return (0);
	stack->list = malloc(sizeof(int) * (size));
	if (stack->list == NULL)
		err_handler();
	stack->size = size;
	i = 0;
	while (i < stack->size && arg && arg[i])
	{
		tmp = ft_split(arg[i], ' ');
		if (tmp == NULL || tmp[0] == 0)
			return (0);
		split_cmds(stack, tmp, &idx);
		free_str(tmp);
		i++;
	}
	return (1);
}

void	split_cmds(t_stack *stack, char **arg, int *idx)
{
	int	i;

	i = 0;
	while (arg != NULL && arg[i])
	{
		if (!check_num(arg[i]) || !check_dup(stack, arg[i], *idx))
			err_handler();
		stack->list[(*idx)--] = ft_atoi(arg[i]);
		stack->top++;
		i++;
	}
}

int	get_stack_size(char **arg)
{
	int	isword;
	int	count;
	int	i;
	int	j;

	i = -1;
	count = 0;
	while (arg[++i])
	{
		j = -1;
		isword = 0;
		if (ft_strlen(arg[i]) == 0)
			err_handler();
		while (arg[i][++j])
		{
			if (!isword && arg[i][j] != ' ')
			{
				isword = 1;
				count++;
			}
			if (isword && arg[i][j] == ' ')
				isword = 0;
		}
	}
	return (count);
}
