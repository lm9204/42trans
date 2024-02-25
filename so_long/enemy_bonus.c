/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:32:02 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/25 16:00:09 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	enemy_move(t_obj *obj, t_enemy *ptr)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {1, 0, -1, 0};
	int			range;
	int			tx;
	int			ty;

	range = 96;
	tx = ptr->x;
	ty = ptr->y;
	if (obj->width > tx - range && obj->height > ty - range \
	&& obj->width < tx + range && obj->height < ty + range && ptr->time > 0)
	{
		enemy_pathfind(obj, ptr, dx, dy);
		ptr->time = -50;
	}
	if (ptr->time < 0)
		enemy_pursuit(obj, ptr, dx, dy);
	if (ptr->time >= 0)
		enemy_patrol(obj, ptr);
	if ((tx != ptr->x && ptr->x % 32 == 0) \
	|| (ty != ptr->y && ptr->y % 32 == 0))
		ptr->sprite_idx++;
	if (ptr->sprite_idx >= 3)
		ptr->sprite_idx = 0;
	ptr->time++;
}

static int	_update(t_enemy *enemy, int *cord, int weight)
{
	enemy->path->weight = weight;
	enemy->path->tx = cord[1];
	enemy->path->ty = cord[0];
	while (enemy->path->size > 0)
		pop(enemy->path, &cord);
	return (1);
}

static int	_vcord(t_obj *obj, int nx, int ny)
{
	if (ny < 0 || ny >= obj->map->size_y * 4 || nx < 0 \
	|| nx >= obj->map->size_x * 4)
		return (0);
	return (1);
}

static int	_select(t_obj *obj, t_enemy *enemy, const int *dx, const int *dy)
{
	int	i;
	int	ny;
	int	nx;

	while (enemy->path->weight > 1)
	{
		i = -1;
		while (++i < 4)
		{
			ny = enemy->path->ty + dy[i];
			nx = enemy->path->tx + dx[i];
			if (!_vcord(obj, nx, ny) \
			|| enemy->path->visited[ny][nx] != enemy->path->weight)
				continue ;
			enemy->path->visited[ny][nx] *= -1;
			enemy->path->ty = ny;
			enemy->path->tx = nx;
			enemy->path->weight--;
			break ;
		}
	}
	enemy->path->weight = 2;
	return (1);
}

void	enemy_pathfind(t_obj *obj, t_enemy *e, const int *dx, const int *dy)
{
	int	*cord;
	int	n[4];

	reset_visitied(e->path->visited, obj->map->size_x, obj->map->size_y);
	cord = malloc(sizeof(int) * 2);
	push(e->path, e->x / 8, e->y / 8);
	e->path->visited[e->y / 8][e->x / 8] = 1;
	while (e->path->size > 0 && pop(e->path, &cord) == 1)
	{
		n[3] = -1;
		n[0] = e->path->visited[cord[0]][cord[1]] + 1;
		while (++(n[3]) < 4)
		{
			n[1] = cord[0] + dy[n[3]];
			n[2] = cord[1] + dx[n[3]];
			if (!_vcord(obj, n[2], n[1]) || e->path->visited[n[1]][n[2]] > 0 \
			|| obj->map->tile[n[1] / 4][n[2] / 4] == '1')
				continue ;
			e->path->visited[n[1]][n[2]] = n[0];
			push(e->path, n[2], n[1]);
			if (n[1] == obj->height / 8 && n[2] == obj->width / 8)
				if (_update(e, cord, n[0]) && _select(obj, e, dx, dy))
					return ;
		}
	}
}
