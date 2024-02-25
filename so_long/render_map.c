/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:27:20 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/19 11:31:55 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	draw_sprite(t_obj *obj, void *img, int x, int y)
{
	if (obj == NULL || img == NULL)
		handle_error(obj);
	mlx_put_image_to_window(obj->p_mlx, obj->p_win, img, x, y);
}

void	render_map_border(t_obj *obj, int x, int y)
{
	int	sidx;

	if (y == 0 && (x == 0 || x == obj->map->size_x - 1))
		sidx = x < 1;
	else if (y == obj->map->size_y - 1 && \
	(x == 0 || x == obj->map->size_x - 1))
		sidx = (x < 1) + 2;
	else if (x == 0 || x == obj->map->size_x - 1)
		sidx = 5;
	else if (y == 0 || y == obj->map->size_y - 1)
		sidx = 4;
	else
		sidx = 6;
	draw_sprite(obj, obj->map->border[sidx]->img, x * 32, y * 32);
}

void	render_map_inner(t_obj *obj, int x, int y)
{
	t_img	*img;

	img = obj->map->land[0]->img;
	if (x < 1 || obj->map->size_x - 1 == x \
	|| y < 1 || obj->map->size_y - 1 == y)
		return ;
	if (obj->map->tile[y][x] == '1')
		img = obj->map->wall[0]->img;
	draw_sprite(obj, img, x * 32, y * 32);
	if (obj->map->tile[y][x] == 'E')
		draw_sprite(obj, obj->map->objs[2]->img, x * 32, y * 32);
	if (x > 0 && x < obj->map->size_x && y > 0 && y < obj->map->size_y \
	&& obj->map->tile[y][x] != '1')
		render_map_grass(obj, x, y);
	if (obj->map->tile[y][x] == 'C')
	{
		img = obj->map->objs[0]->img;
		draw_sprite(obj, img, x * 32, y * 32);
	}
}

void	render_map_grass_corner(t_obj *obj, int x, int y)
{
	if (obj->map->tile[y - 1][x + 1] == '1')
		draw_sprite(obj, obj->map->land[9]->img, x * 32, y * 32);
	if (obj->map->tile[y + 1][x + 1] == '1')
		draw_sprite(obj, obj->map->land[10]->img, x * 32, y * 32);
	if (obj->map->tile[y + 1][x - 1] == '1')
		draw_sprite(obj, obj->map->land[11]->img, x * 32, y * 32);
	if (obj->map->tile[y - 1][x - 1] == '1')
		draw_sprite(obj, obj->map->land[12]->img, x * 32, y * 32);
}

void	render_map_grass(t_obj *obj, int x, int y)
{
	if (obj->map->tile[y - 1][x] == '1' && obj->map->tile[y][x + 1] == '1')
		draw_sprite(obj, obj->map->land[2]->img, x * 32, y * 32);
	else if (obj->map->tile[y - 1][x] == '1')
		draw_sprite(obj, obj->map->land[1]->img, x * 32, y * 32);
	else if (obj->map->tile[y][x + 1] == '1')
		draw_sprite(obj, obj->map->land[3]->img, x * 32, y * 32);
	if (obj->map->tile[y][x + 1] == '1' && obj->map->tile[y + 1][x] == '1')
		draw_sprite(obj, obj->map->land[4]->img, x * 32, y * 32);
	else if (obj->map->tile[y + 1][x] == '1')
		draw_sprite(obj, obj->map->land[5]->img, x * 32, y * 32);
	else if (obj->map->tile[y][x + 1] == '1')
		draw_sprite(obj, obj->map->land[3]->img, x * 32, y * 32);
	if (obj->map->tile[y + 1][x] == '1' && obj->map->tile[y][x - 1] == '1')
		draw_sprite(obj, obj->map->land[6]->img, x * 32, y * 32);
	else if (obj->map->tile[y + 1][x] == '1')
		draw_sprite(obj, obj->map->land[5]->img, x * 32, y * 32);
	else if (obj->map->tile[y][x - 1] == '1')
		draw_sprite(obj, obj->map->land[7]->img, x * 32, y * 32);
	if (obj->map->tile[y - 1][x] == '1' && obj->map->tile[y][x - 1] == '1')
		draw_sprite(obj, obj->map->land[8]->img, x * 32, y * 32);
	else if (obj->map->tile[y - 1][x] == '1')
		draw_sprite(obj, obj->map->land[1]->img, x * 32, y * 32);
	else if (obj->map->tile[y][x - 1] == '1')
		draw_sprite(obj, obj->map->land[7]->img, x * 32, y * 32);
	render_map_grass_corner(obj, x, y);
}
