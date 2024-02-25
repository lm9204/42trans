/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:47:32 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/18 14:59:58 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_sprite_group(char *line, int *idx_list)
{
	char	**str;
	char	*tmp;

	if (line[0] != '[')
		return (0);
	tmp = ft_strtrim(line, "[]\n");
	str = ft_split(tmp, ':');
	*idx_list = ft_atoi(str[1]);
	return (1);
}

void	destory_object(t_obj *obj)
{
	if (obj->p_win == NULL)
	{
		free(obj->p_mlx);
		exit(0);
	}
	mlx_destroy_window(obj->p_mlx, obj->p_win);
	mlx_destroy_image(obj->p_mlx, obj->player->img);
	destory_sprite(obj->p_mlx, obj->map->border, \
	obj->file->init_list[M_BORDER]);
	destory_sprite(obj->p_mlx, obj->map->land, obj->file->init_list[M_LAND]);
	destory_sprite(obj->p_mlx, obj->map->wall, obj->file->init_list[M_TREE]);
	destory_sprite(obj->p_mlx, obj->map->objs, obj->file->init_list[M_OBJ]);
	free(obj->p_mlx);
}

void	destory_sprite(void	*p_mlx, t_img **imgs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(p_mlx, imgs[i]->img);
		i++;
	}
}

void	handle_error(t_obj *obj)
{
	ft_putendl_fd("Error", 2);
	destory_object(obj);
	exit(1);
}
