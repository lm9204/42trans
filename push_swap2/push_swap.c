/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/29 12:52:12 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*org;
	t_stack	a;
	t_stack	b;
	int		size;

	if (argc == 1)
		return (0);
	size = get_stack_size(argv + 1);
	init_list(&a, argv + 1, size, 'a');
	init_list(&b, NULL, size, 'b');
	init_idx(&a);
	org = copy_list(&a);
	sort_list(&a, &b);
	if (a.size <= 5)
		exit(0);
	replace_origin(&a, org);
	sort_list(org, &b);
	exit(0);
}

void	init_list(t_stack *s, char **arg, int size, char name)
{
	char		**tmp;
	int			idx;
	int			i;

	idx = size - 1;
	s->top = -1;
	s->name = name;
	if (size == 0)
		err_handler();
	s->list = malloc(sizeof(t_element *) * (size));
	if (s->list == NULL)
		err_handler();
	s->size = size;
	i = 0;
	while (i < s->size && arg && arg[i])
	{
		tmp = ft_split(arg[i], ' ');
		if (tmp == NULL || tmp[0] == 0)
			err_handler();
		split_cmds(s, tmp, &idx);
		free_str(tmp);
		i++;
	}
}

void	split_cmds(t_stack *stack, char **arg, int *idx)
{
	int	i;

	i = 0;
	while (arg != NULL && arg[i])
	{
		if (!check_num(arg[i]) || !check_dup(stack, arg[i], *idx))
			err_handler();
		stack->list[(*idx)--] = create_node(ft_atoi(arg[i]));
		stack->top++;
		i++;
	}
}

void	init_idx(t_stack *s)
{
	t_element	**list;
	int			i;
	int			j;

	list = malloc(sizeof(t_element *) * s->size);
	if (list == NULL)
		return ;
	i = -1;
	while (++i < s->size)
		list[i] = s->list[i];
	while (--i >= 0)
	{
		j = 0;
		while (j < s->size)
		{
			if (list[i]->val <= list[j]->val)
				list[j]->idx++;
			j++;
		}
	}
	while (++i < s->size)
		list[i]->base_3 = base_3(list[i]->idx);
	free(list);
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
