/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:23:10 by yeondcho          #+#    #+#             */
/*   Updated: 2024/01/25 21:48:51 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	f(void)
{
	system("leaks checker");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_node	*list;
	int		size;

	atexit(f);
	if (argc < 2)
		exit(0);
	list = NULL;
	size = get_stack_size(argv + 1);
	init_stack(&a, argv + 1, size);
	init_stack(&b, NULL, size);
	getcmds(&list);
	if (!validate_inputcmds(&list))
		err_handler();
	if (validate_pushswap(&a, &b, &list))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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

void	init_stack(t_stack *stack, char **cmds, int size)
{
	stack->list = (int *)malloc(sizeof(int) * size);
	stack->top = -1;
	stack->size = size;
	if (cmds)
	{
		if (!insert_stack(stack, cmds, size))
			err_handler();
	}
}

void	err_handler(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
