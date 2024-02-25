/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:41:22 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/25 10:32:53 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	get_map_width(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != '\n')
			count++;
		i++;
	}
	return (count);
}

void	restore_tile(t_map *map)
{
	int	y;
	int	x;

	y = 1;
	while (y < map->size_y)
	{
		x = 1;
		while (x < map->size_x)
		{
			if (map->tile[y][x] == '2')
				map->tile[y][x] = '0';
			if (map->tile[y][x] == '3')
				map->tile[y][x] = 'E';
			if (map->tile[y][x] == 'c')
				map->tile[y][x] = 'C';
			x++;
		}
		y++;
	}
}

int	check_route(t_map *map, int x, int y, int cnt)
{
	if (cnt == map->collect && map->isexitable)
	{
		restore_tile(map);
		return (1);
	}
	if (x > map->size_x || x < 1 || y > map->size_y || y < 1 \
	|| map->tile[y][x] == '1' || map->tile[y][x] == '2')
		return (0);
	else if (map->tile[y][x] == 'E')
	{
		map->isexitable = 1;
		map->tile[y][x] = '3';
	}
	else if (map->tile[y][x] == 'C')
	{
		cnt++;
		map->tile[y][x] = 'c';
	}
	else if (map->tile[y][x] == '0')
		map->tile[y][x] = '2';
	if (check_route(map, x + 1, y, cnt) || check_route(map, x - 1, y, cnt) \
	|| check_route(map, x, y + 1, cnt) || check_route(map, x, y - 1, cnt))
		return (1);
	return (0);
}

void	get_player_spawn(t_obj *obj)
{
	int	x;
	int	y;

	y = 1;
	while (y < obj->map->size_y - 1)
	{
		x = 1;
		while (x < obj->map->size_x - 1)
		{
			if (obj->map->tile[y][x] == 'P')
			{
				obj->width = x * 32 + 16;
				obj->height = y * 32 + 24;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	validate_border(t_obj *obj)
{
	int	wallcnt;
	int	i;
	int	j;

	i = 0;
	while (i < obj->map->size_y)
	{
		if (obj->map->tile[i][0] != '1' \
		|| obj->map->tile[i][obj->map->size_x - 1] != '1')
			handle_error(obj);
		if (i == 0 || i == obj->map->size_y - 1)
		{
			wallcnt = 0;
			j = 0;
			while (j < obj->map->size_x)
			{
				if (obj->map->tile[i][j] == '1')
					wallcnt++;
				j++;
			}
			if (wallcnt != obj->map->size_x)
				handle_error(obj);
		}
		i++;
	}
}
