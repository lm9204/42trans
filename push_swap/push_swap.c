/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/05 19:31:01 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_list(&a, argv + 1, argc - 1);
	init_list(&b, NULL, 0);
	print_list(&a);
	print_list(&b);
}

void	init_list(t_element **list, char **arg, int size)
{
	char		**tmp;
	int			idx;
	int			i;
	int			n;

	i = 0;
	idx = 0;
	while (i < size && arg[i])
	{
		tmp = ft_split(arg[i], ' ');
		if (tmp == NULL)
			*tmp = arg[i];
		while (*tmp)
		{
			printf("%s\n", *tmp);
			if (!check_num(*tmp))
				err_handler();
			n = ft_atoi(*tmp);
			if (!addlist(list, create_node(n, idx)))
				err_handler();
			idx++;
			tmp++;
		}
		i++;
	}
	convert_4(list);
}

int	get_stack_size(char *stack)
{
	int	count;

	count = 0;
	while (*stack)
	{
		if (*stack == ' ')
			count++;
		stack++;
	}
	return (count);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
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

void	print_list(t_element **list)
{
	t_element			*ptr;
	int					i;
	unsigned long long	j;

	i = 0;
	ptr = *list;
	if (!ptr)
		printf("no node on list\n");
	while (ptr)
	{
		j = 1;
		printf("%d번째 : %d %lld | idx : %d\n", i, ptr->val, ptr->base_4, ptr->idx);
		while (j <= ptr->base_4)
		{
			printf("%lld자릿수 : %llu\n", j, (ptr->base_4 / j) % 10);
			j *= 10;
		}
		ptr = ptr->next;
		i++;
	}
}
