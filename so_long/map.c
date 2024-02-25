/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:41:56 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/18 14:57:07 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	init_map(t_obj *obj, char *map_path)
{
	obj->map = malloc(sizeof(t_map));
	obj->map->size_x = 0;
	obj->map->size_y = 0;
	obj->map->collect = 0;
	obj->map->isexitable = 0;
	create_tile(obj, map_path);
	obj->p_win = mlx_new_window(obj->p_mlx, \
	obj->map->size_x * 32, obj->map->size_y * 32, "so_long");
	get_player_spawn(obj);
	obj->map->land = load_map_tile(obj, M_LAND);
	obj->map->border = load_map_tile(obj, M_BORDER);
	obj->map->wall = load_map_tile(obj, M_TREE);
	obj->map->objs = load_map_tile(obj, M_OBJ);
	validate_border(obj);
	if (!check_route(obj->map, obj->width / 32, obj->height / 32, 0))
		handle_error(obj);
	return (1);
}

t_img	**load_map_tile(t_obj *obj, int sprite_name)
{
	t_img	**res;
	int		size;
	int		idx;
	int		i;

	size = obj->file->init_list[sprite_name];
	res = malloc(sizeof(t_img *) * size);
	if (res == NULL)
		return (0);
	i = 0;
	idx = 0;
	while (i != sprite_name)
		idx += obj->file->init_list[i++];
	i = 0;
	while (i < size)
	{
		res[i] = create_img(obj, obj->file->list[idx + i]);
		i++;
	}
	return (res);
}

void	create_tile(t_obj *obj, char *map_path)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	if (!validate_map(map_path, &obj->map->size_y, &obj->map->size_x, \
	&obj->map->collect))
		handle_error(obj);
	fd = open(map_path, O_RDONLY);
	obj->map->tile = malloc(sizeof(int *) * obj->map->size_y);
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		obj->map->tile[++i] = malloc(sizeof(int) * obj->map->size_x);
		j = 0;
		while (j < obj->map->size_x)
		{
			obj->map->tile[i][j] = line[j];
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	validate_map(char *map_path, int *map_height, int *map_width, int *c)
{
	char	*line;
	int		fd;
	int		p;
	int		e;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	*map_width = get_map_width(line);
	if (*map_width == 0)
		return (0);
	p = 0;
	e = 0;
	while (line)
	{
		if ((int)(get_map_width(line)) != *map_width || \
		!validate_point(line, &p, &e, c))
			return (0);
		free(line);
		(*map_height)++;
		line = get_next_line(fd);
	}
	if (p != 1 || e != 1 || *c == 0)
		return (0);
	close(fd);
	return (1);
}

int	validate_point(char *line, int *p, int *e, int *c)
{
	int	size;
	int	i;

	i = 0;
	size = get_map_width(line) - 1;
	while (i < size && line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P' \
		&& line[i] != 'C' && line[i] != 'E')
			return (0);
		if (line[i] == 'P')
			(*p)++;
		if (line[i] == 'E')
			(*e)++;
		if (line[i] == 'C')
			(*c)++;
		i++;
	}
	return (1);
}
