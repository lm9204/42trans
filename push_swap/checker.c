/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:23:10 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/03 19:27:27 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_node	*list;
	int		size;

	if (argc < 2)
		exit(0);
	list = NULL;
	size = get_stack_size(argv[1]);
	init_stack(&a, argv[1], size);
	init_stack(&b, NULL, size);
	getcmds(&list);
	if (!validate_inputcmds(&list))
		err_handler();
	if (validate_pushswap(&a, &b, &list))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// test_print(&a);
	exit(0);
}

void	getcmds(t_node **head)
{
	t_node	*new;
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (line)
		{
			new = malloc(sizeof(t_node) * 1);
			if (new == NULL)
				return ;
			new->cmd = ft_substr(line, 0, ft_strlen(line) - 1);
			new->next = NULL;
			if (!(*head))
				*head = new;
			else
				node_addback(head, new);
			free(line);
		}
		line = get_next_line(0);
	}
}

void	node_addback(t_node **list, t_node *node)
{
	t_node	*ptr;

	ptr = *list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = node;
}

int	validate_pushswap(t_stack *a, t_stack *b, t_node **list)
{
	t_node	*ptr;

	ptr = *list;
	while (ptr)
	{
		printf("execute cmds : %s\n", ptr->cmd);
		execute_cmds(a, b, ptr->cmd);
		ptr = ptr->next;
	}
	return (validate_sort(a, b));
}

int	validate_sort(t_stack *a, t_stack *b)
{
	int	i;

	if (b->top != -1)
		return (0);
	i = a->top;
	while (i > 0)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	init_stack(t_stack *stack, char *cmds, int size)
{
	stack->stack = (int *)malloc(sizeof(int) * size);
	stack->top = -1;
	stack->size = size;

	if (cmds)
	{
		if (!insert_stack(stack, cmds))
			err_handler();
	}
}

int	validate_inputcmds(t_node **list)
{
	t_node		*ptr;
	const char	*cmds[11] = {"sa", "sb", "ss", "pa", "pb", \
					"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	ptr = *list;
	while (ptr)
	{
		i = 0;
		while (i < 11)
		{
			if (ft_strncmp(ptr->cmd, cmds[i], ft_strlen(ptr->cmd)) == 0)
				return (1);
			i++;
		}
		ptr = ptr->next;
	}
	return (0);
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
