/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:33:28 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/25 10:37:34 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	enemy_pursuit(t_obj *obj, t_enemy *enemy, const int *dx, const int *dy)
{
	int	tx;
	int	ty;
	int	x;
	int	y;

	tx = enemy->path->tx;
	ty = enemy->path->ty;
	x = enemy->x / 8;
	y = enemy->y / 8;
	if (x == tx && y == ty)
		enemy_track(obj, enemy, dx, dy);
	if (x > tx)
		enemy->direction = 1;
	else if (y > ty)
		enemy->direction = 3;
	else if (x < tx)
		enemy->direction = 2;
	else if (y < ty)
		enemy->direction = 0;
	if (enemy->direction > 3)
		enemy->direction = 0;
	direction_collision(obj, enemy, 3);
}

void	enemy_track(t_obj *obj, t_enemy *enemy, const int *dx, const int *dy)
{
	int	i;
	int	ny;
	int	nx;

	if (obj->width > enemy->x - 24 && obj->height > enemy->y - 24 \
	&& obj->width < enemy->x + 24 && obj->height < enemy->y + 24 \
	&& obj->player->hp_animation == 0)
	{
		obj->player->hp--;
		obj->player->hp_animation = 50;
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		ny = enemy->y / 8 + dy[i];
		nx = enemy->x / 8 + dx[i];
		if (enemy->path->visited[ny][nx] == (enemy->path->weight + 1) * -1)
		{
			enemy->path->ty = ny;
			enemy->path->tx = nx;
			enemy->path->weight++;
			return ;
		}
	}
}

void	enemy_patrol(t_obj *obj, t_enemy *enemy)
{
	int	movement_time;
	int	tx;
	int	ty;

	srand((unsigned int)time(NULL));
	movement_time = (rand() + enemy->id) % 250;
	tx = enemy->x;
	ty = enemy->y;
	if (enemy->time > movement_time)
	{
		enemy->direction = (rand() + enemy->id) % 4;
		enemy->time = 0;
	}
	if (enemy->direction > 3)
		enemy->direction = 0;
	if (enemy->time % 2 == 0)
		if (!direction_collision(obj, enemy, 2))
			enemy->direction = (rand() + enemy->id) % 4;
	if (tx == enemy->x && ty == enemy->y)
		return ;
	if ((tx != enemy->x && enemy->x % 32 == 0) \
	|| (ty != enemy->y && enemy->y % 32 == 0))
		enemy->sprite_idx++;
	if (enemy->sprite_idx >= 3)
		enemy->sprite_idx = 0;
}

int	direction_collision(t_obj *obj, t_enemy *enemy, int distance)
{
	if (enemy->direction == 3 \
	&& enemy_collision(obj, enemy->x, enemy->y - distance))
		enemy->y -= distance;
	else if (enemy->direction == 2 \
	&& enemy_collision(obj, enemy->x + distance, enemy->y))
		enemy->x += distance;
	else if (enemy->direction == 0 \
	&& enemy_collision(obj, enemy->x, enemy->y + distance))
		enemy->y += distance;
	else if (enemy->direction == 1 \
	&& enemy_collision(obj, enemy->x - distance, enemy->y))
		enemy->x -= distance;
	else
		return (0);
	return (1);
}

int	enemy_collision(t_obj *obj, int mx, int my)
{
	int	x;
	int	y;

	y = my / 32;
	x = mx / 32;
	if (obj->map->tile[y][x] == '1')
		return (0);
	return (1);
}
