/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/06 18:01:41 by yeondcho         ###   ########.fr       */
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

void	init_list(t_stack *s, char **arg, int size)
{
	char		**tmp;
	int			idx;
	int			i;
	int			n;

	i = 0;
	idx = 0;
	s->list = malloc(sizeof(t_element) * (get_stack_size(arg) + 1));
	if (s->list == NULL)
		err_handler();
	s->size = get_stack_size(arg);
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
			idx++;
			tmp++;
		}
		i++;
	}
}

int	get_stack_size(char **arg)
{
	int	count;
	int	i;

	count = 0;
	while (*arg)
	{
		i = 0;
		while (*arg[i])
		{
			if (*arg[i] != ' ')
				count++;
			i++;
		}
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
