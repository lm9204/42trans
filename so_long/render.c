/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:24:17 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/22 20:25:19 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	render_frame(t_obj *obj)
{
	render_map(obj, obj->width / 32, obj->height / 32);
	render_ui(obj);
	mlx_put_image_to_window(obj->p_mlx, obj->p_win, obj->player->img, \
	obj->width - 12, obj->height - 24);
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
			x++;
		}
		y++;
	}
}

void	render_map(t_obj *obj, int pos_x, int pos_y)
{
	int	x;
	int	y;

	y = pos_y - 1;
	while (y <= pos_y + 1)
	{
		x = pos_x - 1;
		while (x <= pos_x + 1)
		{
			render_map_border(obj, x, y);
			render_map_inner(obj, x, y);
			x++;
		}
		y++;
	}
}

void	render_ui(t_obj *obj)
{
	char	*tmp;

	if (obj->cmd == 0)
		return ;
	tmp = ft_itoa(obj->cmd / 32);
	render_map_border(obj, 0, 0);
	mlx_string_put(obj->p_mlx, obj->p_win, 10, 10, 0x00FFFFFF, tmp);
	free(tmp);
}
