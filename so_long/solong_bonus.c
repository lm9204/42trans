/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:32:08 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/25 16:02:50 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	f(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_obj	obj;
	int		fd;

	atexit(f);
	if (argc != 2)
		handle_error(&obj);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		handle_error(&obj);
	obj.cmd = 0;
	obj.file = init_file(&obj, F_SPRITE);
	obj.p_mlx = mlx_init();
	obj.p_win = NULL;
	init_player_sprite(&obj);
	init_enemy(&obj);
	init_map(&obj, argv[1]);
	init_render_map(&obj);
	mlx_hook(obj.p_win, 2, 0, on_press, &obj);
	mlx_hook(obj.p_win, 17, 0, on_destory, &obj);
	mlx_loop_hook(obj.p_mlx, render_frame, &obj);
	mlx_loop(obj.p_mlx);
	close(fd);
}

void	get_file_path(t_obj *obj, t_file *file, int fd, int size)
{
	char	*line;
	char	*tmp;
	int		i;
	int		idx;

	line = get_next_line(fd);
	idx = 0;
	i = 0;
	while (i < size && line != NULL)
	{
		if (check_sprite_group(line, &file->init_list[idx]))
			idx++;
		else
		{
			tmp = ft_strtrim(line, "\n");
			if (ft_strlen(tmp) == 0)
				handle_error(obj);
			file->list[i++] = tmp;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (i != size - idx)
		handle_error(obj);
	file->list[i] = 0;
}

void	init_player_sprite(t_obj *obj)
{
	int		i;

	obj->player = malloc(sizeof(t_player));
	if (obj->player == NULL)
		handle_error(obj);
	obj->player->anime_sprite = malloc(sizeof(int) * 4);
	if (obj->player->anime_sprite == NULL)
		handle_error(obj);
	obj->player->hp = 3;
	obj->player->hp_animation = 0;
	obj->player->anime_idx = 0;
	obj->player->sprite_idx = 0;
	obj->player->sprites = get_sprites(obj, M_PLAYER);
	i = 0;
	while (i < 4)
	{
		obj->player->anime_sprite[i] = i;
		if (i == 3)
			obj->player->anime_sprite[i] = 1;
		i++;
	}
}

t_img	**get_sprites(t_obj *obj, int sprite_name)
{
	t_img	**res;
	int		size;
	int		idx;
	int		i;

	size = obj->file->init_list[sprite_name];
	res = malloc(sizeof(t_img **) * (size));
	if (res == NULL)
		return (NULL);
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

t_img	*create_img(t_obj *obj, char *path)
{
	t_img	*res;

	res = malloc(sizeof(t_img));
	if (res == NULL)
		return (NULL);
	if (path)
	{
		res->img = mlx_xpm_file_to_image(obj->p_mlx, path, &res->x, &res->y);
	}
	else
		res->img = mlx_new_image(obj->p_mlx, res->x, res->y);
	if (res->img == NULL)
		return (NULL);
	res->addr = mlx_get_data_addr(res->img, &res->bits_per_pixel, \
	&res->line_length, &res->endian);
	return (res);
}
