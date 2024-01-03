/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:22:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/03 20:03:00 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		size;

	if (argc != 2)
		err_handler();
	size = get_stack_size(argv[1]);
	init_stack(&a, size);
	init_stack(&b, size);
	if (!insert_stack(&a, argv[1]))
		err_handler();
	
}

void	init_stack(t_stack *stack, int size)
{
	stack->stack = (int *)malloc(sizeof(int) * size);
	stack->top = -1;
	stack->size = size;
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

int	insert_stack(t_stack *stack, char *stack_str)
{
	char	**data;
	int		i;

	data = ft_split(stack_str, ' ');
	if (data == NULL)
		return (-1);
	i = stack->size - 1;
	while (i > 0)
	{
		if (!check_num(data[stack->size - i - 1]))
			err_handler();
		stack->stack[i] = ft_atoi(data[stack->size - i - 1]);
		i--;
	}
	return (1);
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

void	err_handler(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	test_print(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		printf("%d번째 : %d\n", i, s->stack[s->top - i]);
		i++;
	}
}