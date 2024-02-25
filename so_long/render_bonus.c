/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:24:17 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/25 16:25:24 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	render_frame(t_obj *obj)
{
	void	*target_img;
	int		sprite;

	sprite = obj->player->sprite_idx * 3 + \
	obj->player->anime_sprite[obj->player->anime_idx];
	target_img = obj->player->sprites[sprite]->img;
	if (obj->player->hp_animation > 0)
		obj->player->hp_animation -= 2;
	if (obj->player->hp == 0)
	{
		printf("%p %p %p\n", obj->file, obj->file->list);
		destory_object(obj);
		exit(0);
	}
	render_map(obj, obj->width, obj->height);
	render_ui(obj);
	render_enemy(obj);
	if (obj->player->hp_animation % 10 == 0)
		mlx_put_image_to_window(obj->p_mlx, obj->p_win, target_img, \
		obj->width - 12, obj->height - 20);
	return (1);
}

void	init_render_map(t_obj *obj)
{
	int	x;
	int	y;

	y = 0;
	while (y < obj->map->size_y)
	{
		x = 0;
		while (x < obj->map->size_x)
		{
			render_map_border(obj, x, y);
			render_map_inner(obj, x, y);
			if (obj->map->tile[y][x] == 'M')
				add_enemy(obj, x, y);
			x++;
		}
		y++;
	}
}

//g 0 : vertical 1 : horizental
void	render_map(t_obj *obj, int pos_x, int pos_y)
{
	int	g[2];
	int	tile_x;
	int	tile_y;

	tile_x = pos_x / 32;
	tile_y = pos_y / 32;
	g[0] = calc_gap_tile(tile_y, pos_y);
	g[1] = calc_gap_tile(tile_x, pos_x);
	render_map_border(obj, tile_x, tile_y);
	render_map_inner(obj, tile_x, tile_y);
	render_map_border(obj, tile_x + g[1], tile_y);
	render_map_inner(obj, tile_x + g[1], tile_y);
	render_map_border(obj, tile_x, tile_y + g[0]);
	render_map_inner(obj, tile_x, tile_y + g[0]);
	render_map_border(obj, tile_x, tile_y + g[0] * -1);
	render_map_inner(obj, tile_x, tile_y + g[0] * -1);
	render_map_border(obj, tile_x + g[1], tile_y + g[0]);
	render_map_inner(obj, tile_x + g[1], tile_y + g[0]);
	render_map_border(obj, tile_x + g[1], tile_y + g[0] * -1);
	render_map_inner(obj, tile_x + g[1], tile_y + g[0] * -1);
}

void	render_ui(t_obj *obj)
{
	char	*cmd;
	char	*hp;

	cmd = ft_itoa(obj->cmd / 32);
	hp = ft_itoa(obj->player->hp);
	render_map_border(obj, 0, 0);
	render_map_border(obj, obj->map->size_x - 1, 0);
	mlx_string_put(obj->p_mlx, obj->p_win, 10, 10, 0x00FFFFFF, cmd);
	mlx_string_put(obj->p_mlx, obj->p_win, (obj->map->size_x * 32) - 10, 10, \
	0x00FFFFFF, hp);
	free(cmd);
	free(hp);
}

void	render_enemy(t_obj *obj)
{
	t_enemy	*ptr;
	int		px;
	int		py;

	ptr = obj->enemy;
	px = obj->width;
	py = obj->height;
	while (ptr)
	{
		render_map(obj, ptr->x, ptr->y);
		ptr = ptr->next;
	}
	ptr = obj->enemy;
	while (ptr)
	{
		enemy_move(obj, ptr);
		mlx_put_image_to_window(obj->p_mlx, obj->p_win, \
		obj->en_sprite[ptr->direction * 3 + ptr->sprite_idx]->img, \
		ptr->x - 12, ptr->y - 24);
		ptr = ptr->next;
	}
}
