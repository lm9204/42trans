/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/17 22:35:01 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*org;
	t_stack	a;
	t_stack	b;
	int		size;

	argc = 0;
	size = get_stack_size(argv + 1);
	init_list(&a, argv + 1, size, 'a');
	init_list(&b, NULL, size, 'b');
	init_idx(&a);
	org = copy_list(&a);
	sort_list(&a, &b);
	replace_origin(&a, org);
	sort_list(org, &b);
}

void	init_list(t_stack *s, char **arg, int size, char name)
{
	char		**tmp;
	int			idx;
	int			i;

	idx = size - 1;
	s->top = -1;
	s->name = name;
	s->list = malloc(sizeof(t_element *) * (size + 1));
	if (s->list == NULL)
		err_handler();
	s->size = size;
	i = 0;
	while (i < s->size && arg && arg[i])
	{
		tmp = ft_split(arg[i], ' ');
		if (tmp == NULL)
			*tmp = arg[i];
		while (*tmp)
		{
			if (!check_num(*tmp) || !check_dup(s, *tmp, idx))
				err_handler();
			s->list[idx] = create_node(ft_atoi(*tmp));
			s->top++;
			idx--;
			tmp++;
		}
		i++;
	}
}
//copy_list 사용 
void	init_idx(t_stack *s)
{
	t_element	**list;
	t_element	*tmp;
	int			i;
	int			j;

	list = malloc(sizeof(t_element *) * s->size);
	if (list == NULL)
		return ;
	i = 0;
	while (i < s->size)
	{
		list[i] = s->list[i];
		i++;
	}
	i = 0;
	while (i < s->size - 1)
	{
		j = 0;
		while (j < s->size - i - 1)
		{
			if (list[j]->val > list[j + 1]->val)
			{
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < s->size)
	{
		list[i]->idx = i;
		list[i]->base_3 = base_3(i);
		i++;
	}
}

int	get_stack_size(char **arg)
{
	int	isword;
	int	count;
	int	i;
	int	j;

	i = 0;
	isword = 0;
	count = 0;
	while (arg[i])
	{
		j = 0;
		isword = 0;
		while (arg[i][j])
		{
			if (!isword && arg[i][j] != ' ')
			{
				isword = 1;
				count++;
			}
			if (isword && arg[i][j] == ' ')
				isword = 0;
			j++;
		}
		i++;
	}
	return (count);
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

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
			err_handler();
		i++;
	}
	return (1);
}

void	err_handler(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	print_list(t_stack *s)
{
	int	i;

	i = s->top;
	printf("------------------------------------------------------------\n");
	printf("stack name : %c\n", s->name);
	printf("stack size : %d\n", s->size);
	printf("stack top idx : %d\n",s->top);
	printf("------------------------------------------------------------\n");
	printf("print from top stack\n");
	if (i < 0)
		printf("nothing in stack\n");
	while (i >= 0)
	{
		// if (i % 4 == 3)
			// printf("---------------------------------------------------------------\n");
		printf("idx:%3d |  init_idx:%3d val:%10d base_3:%20s\n", i, s->list[i]->idx, s->list[i]->val, s->list[i]->base_3);
		i--;
	}
}
