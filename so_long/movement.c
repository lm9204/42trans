/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:07:36 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/17 06:39:21 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	on_press(int keycode, t_obj *obj)
{
	player_state(obj, keycode);
	if (keycode == K_ESC)
	{
		mlx_destroy_window(obj->p_mlx, obj->p_win);
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
	if (keycode == K_W || keycode == K_A)
		if (is_movable(obj, keycode, -8))
			obj->cmd += 8;
	if (keycode == K_S || keycode == K_D)
		if (is_movable(obj, keycode, 8))
			obj->cmd += 8;
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
	if (check_collision(obj, keycode, willmove_cord) == 0)
		return (0);
	else
	{
		obj->height = willmove_cord[0];
		obj->width = willmove_cord[1];
	}
	return (1);
}

int	check_collision(t_obj *obj, int keycode, int move[2])
{
	int	tx;
	int	ty;
	int	x;
	int	y;

	y = (move[0]) / 32;
	x = (move[1]) / 32;
	ty = move[0] + 16;
	tx = move[1] + 16;
	keycode = 0;
	if (obj->map->tile[y][x] == '1')
	{
		if ((move[1] <= tx && tx <= move[1] + 32) \
		|| (move[0] <= ty && ty <= move[0] + 32))
			return (0);
	}
	if (obj->map->tile[y][x] == 'C')
	{
		obj->map->tile[y][x] = '0';
		obj->map->collect--;
	}
	if (obj->map->tile[y][x] == 'E' && obj->map->collect == 0)
		exit(0);
	return (1);
}
