/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:47:32 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/25 16:18:26 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

t_file	*init_file(t_obj *obj, char *file_path)
{
	t_file	*file;
	int		size;
	int		fd;

	size = get_sprite_size(file_path);
	file = malloc(sizeof(t_file));
	file->list = malloc(sizeof(char *) * (size + 1));
	file->init_list = malloc(sizeof(int) * 7);
	if (file->list == NULL || file->init_list == NULL)
		handle_error(obj);
	fd = open(file_path, O_RDONLY);
	get_file_path(obj, file, fd, size);
	return (file);
}

int	check_sprite_group(char *line, int *idx_list)
{
	char	**str;
	char	*tmp;
	int		i;

	if (line[0] != '[')
		return (0);
	tmp = ft_strtrim(line, "[]\n");
	str = ft_split(tmp, ':');
	*idx_list = ft_atoi(str[1]);
	i = 0;
	free(tmp);
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str);
	return (1);
}

void	handle_error(t_obj *obj)
{
	ft_putendl_fd("Error", 2);
	destory_object(obj);
	exit(1);
}

void	destory_object(t_obj *obj)
{
	mlx_destroy_window(obj->p_mlx, obj->p_win);
	destory_sprite(obj->p_mlx, obj->player->sprites, 12);
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
