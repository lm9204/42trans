/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:35:18 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/24 20:33:06 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

t_path	*init_path_queue(int size_x, int size_y)
{
	t_path	*res;
	int		i;

	res = malloc(sizeof(t_path));
	if (res == NULL)
		return (NULL);
	res->visited = init_visited(size_x, size_y);
	res->q = malloc(sizeof(int *) * (size_y * size_x));
	if (res->q == NULL || res->visited == NULL)
		return (NULL);
	i = -1;
	while (++i < size_x * size_y)
	{
		res->q[i] = malloc(sizeof(int) * 2);
		res->q[i][0] = -1;
		res->q[i][1] = -1;
	}
	res->weight = 2;
	res->max_size = size_x * size_y;
	res->size = 0;
	res->fr = -1;
	res->ed = -1;
	res->tx = -1;
	res->ty = -1;
	return (res);
}

int	**init_visited(int size_x, int size_y)
{
	int	**res;
	int	i;
	int	j;

	res = malloc(sizeof(int *) * size_y * 4);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size_y * 4)
	{
		res[i] = malloc(sizeof(int) * size_x * 4);
		if (res[i] == NULL)
			return (NULL);
		j = 0;
		while (j < size_x * 4)
		{
			res[i][j] = 0;
			j++;
		}
		i++;
	}
	return (res);
}

int	pop(t_path *queue, int **res)
{
	if (queue->fr == -1 || queue->size + 1 >= queue->max_size)
		return (-1);
	(*res)[0] = queue->q[queue->fr][0];
	(*res)[1] = queue->q[queue->fr][1];
	queue->fr = (queue->fr + 1) % queue->max_size;
	queue->size--;
	return (1);
}

int	push(t_path *queue, int x, int y)
{
	if (queue->size + 1 >= queue->max_size)
		return (-1);
	queue->ed = (queue->ed + 1) % queue->max_size;
	if (queue->fr == -1)
		queue->fr = queue->ed;
	queue->q[queue->ed][0] = y;
	queue->q[queue->ed][1] = x;
	queue->size++;
	return (1);
}

int	get_queue_size(t_path *queue)
{
	int	fr;
	int	ed;
	int	i;

	fr = queue->fr;
	ed = queue->ed;
	if (fr == ed)
		return (1);
	i = 0;
	while (i < queue->size)
	{
		if (fr == ed)
			break ;
		fr = (fr + 1) % queue->size;
		i++;
	}
	return (i);
}
