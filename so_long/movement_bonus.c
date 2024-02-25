/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:07:36 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/24 20:36:34 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	on_press(int keycode, t_obj *obj)
{
	player_state(obj, keycode);
	if (keycode == K_ESC)
	{
		destory_object(obj);
		exit(0);
	}
	return (1);
}

int	on_destory(t_obj *obj)
{
	destory_object(obj);
	exit(0);
	return (1);
}

void	player_state(t_obj *obj, int keycode)
{
	if (keycode == K_W)
		obj->player->sprite_idx = 3;
	if (keycode == K_A)
		obj->player->sprite_idx = 1;
	if (keycode == K_W || keycode == K_A)
		if (is_movable(obj, keycode, -8))
			obj->cmd += 8;
	if (keycode == K_S)
		obj->player->sprite_idx = 0;
	if (keycode == K_D)
		obj->player->sprite_idx = 2;
	if (keycode == K_S || keycode == K_D)
		if (is_movable(obj, keycode, 8))
			obj->cmd += 8;
	if (obj->width % 32 == 0 || obj->height % 32 == 0)
		obj->player->anime_idx++;
	if (obj->player->anime_idx > 3)
		obj->player->anime_idx = 0;
}

int	is_movable(t_obj *obj, int keycode, int move)
{
	int	curr_cord[2];
	int	willmove_cord[2];

	curr_cord[0] = obj->height;
	curr_cord[1] = obj->width;
	willmove_cord[0] = curr_cord[0];
	willmove_cord[1] = curr_cord[1];
	if (keycode == K_A || keycode == K_D)
		willmove_cord[1] += move;
	if (keycode == K_S || keycode == K_W)
		willmove_cord[0] += move;
	if (check_collision(obj, willmove_cord) == 0)
		return (0);
	else
	{
		obj->height = willmove_cord[0];
		obj->width = willmove_cord[1];
	}
	return (1);
}

int	check_collision(t_obj *obj, int move[2])
{
	int	x;
	int	y;

	y = (move[0]) / 32;
	x = (move[1]) / 32;
	if (obj->map->tile[y][x] == '1')
		return (0);
	if (obj->map->tile[y][x] == 'C')
	{
		obj->map->tile[y][x] = 'c';
		obj->map->collect--;
	}
	if (obj->map->tile[y][x] == 'E' && obj->map->collect == 0)
	{
		destory_object(obj);
		exit(0);
	}
	return (1);
}
