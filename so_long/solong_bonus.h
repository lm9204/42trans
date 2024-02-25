/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:32:55 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/25 11:26:25 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define M_LAND 0
# define M_BORDER 1
# define M_TREE 2
# define M_PLAYER 3
# define M_ENEMY 4
# define M_OBJ 5
# define F_SPRITE "./sprites.txt"

# include <time.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_map
{
	t_img	**border;
	t_img	**land;
	t_img	**wall;
	t_img	**objs;
	int		**tile;
	int		collect;
	int		size_x;
	int		size_y;
	int		isexitable;
}	t_map;

typedef struct s_player
{
	t_img	**sprites;
	int		*anime_sprite;
	int		anime_idx;
	int		sprite_idx;
	int		hp;
	int		hp_animation;
}	t_player;

/* 0 : land
 * 1 : border
 * 2 : tree (inner_wall)
 * 3 : player
 * 4 : enemy - notyet */
typedef struct s_file
{
	char	**list;
	int		*init_list;
}	t_file;

typedef struct s_path
{
	int	**visited;
	int	**q;
	int	weight;
	int	fr;
	int	ed;
	int	size;
	int	max_size;
	int	tx;
	int	ty;
}	t_path;

typedef struct s_enemy
{
	t_path			*path;
	int				id;
	int				sprite_idx;
	int				direction;
	int				time;
	int				x;
	int				y;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_obj
{
	t_player	*player;
	t_enemy		*enemy;
	t_img		**en_sprite;
	t_file		*file;
	t_map		*map;
	void		*p_mlx;
	void		*p_win;
	int			width;
	int			height;
	int			cmd;
}	t_obj;

/*---------------------solong.c---------------------*/
void	init_player_sprite(t_obj *obj);
t_img	*create_img(t_obj *obj, char *path);
t_img	**get_sprites(t_obj *obj, int sprite_name);
// void	get_sprite_location(char *name, int fd);

t_file	*init_file(t_obj *obj, char *file_path);

/*---------------------render.c---------------------*/
int		render_frame(t_obj *obj);
void	render_ui(t_obj *obj);
void	render_map(t_obj *obj, int pos_x, int pos_y);
void	init_render_map(t_obj *obj);
void	animate_image(t_obj *obj);

/*---------------------render_map.c---------------------*/
void	render_map_border(t_obj *obj, int x, int y);
void	render_map_inner(t_obj *obj, int x, int y);
void	render_map_grass(t_obj *obj, int x, int y);
void	render_map_grass_corner(t_obj *obj, int x, int y);

/*---------------------hook_movement.c---------------------*/
void	player_state(t_obj *obj, int keycode);
int		on_press(int keycode, t_obj *obj);
int		on_release(int keycode, t_obj *obj);
int		on_destory(t_obj *obj);
int		is_movable(t_obj *obj, int keycode, int move);
int		check_collision(t_obj *obj, int move[2]);

/*map.c*/
t_img	**load_map_tile(t_obj *obj, int sprite_name);
int		init_map(t_obj *obj, char *map_path);
void	get_player_spawn(t_obj *obj);
void	validate_border(t_obj *obj);

void	create_tile(t_obj *obj, char *map_path);
int		validate_map(char *map_path, int *map_height, int *map_width, int *c);
int		validate_point(char *line, int *p, int *e, int *c);
/*---------------------sprite.c---------------------*/
int		get_sprite_size(char *file_path);

/* map_parse.c*/
int		get_map_width(char *line);
int		check_route(t_map *map, int x, int y, int count);
/* solong_utils*/
int		check_sprite_group(char *line, int *idx_list);
void	handle_error(t_obj *obj);
void	destory_object(t_obj *obj);
void	destory_sprite(void	*p_mlx, t_img **imgs, int size);
void	get_file_path(t_obj *obj, t_file *file, int fd, int size);

/*---------------------enemy_bonus.c---------------------*/
void	render_enemy(t_obj *obj);
void	enemy_patrol(t_obj *obj, t_enemy *enemy);
void	init_enemy(t_obj *obj);
int		enemy_collision(t_obj *obj, int mx, int my);
void	enemy_track(t_obj *obj, t_enemy *enemy, const int *dx, const int *dy);
void	enemy_pursuit(t_obj *obj, t_enemy *enemy, const int *dx, const int *dy);
void	enemy_pathfind(t_obj *obj, t_enemy *enemy, \
const int *dx, const int *dy);
void	enemy_move(t_obj *obj, t_enemy *ptr);
void	add_enemy(t_obj *obj, int x, int y);
void	reset_visitied(int **visited, int size_x, int size_y);

int		direction_collision(t_obj *obj, t_enemy *enemy, int distance);

int		**init_visited(int size_x, int size_y);
t_path	*init_path_queue(int size_x, int size_y);
int		pop(t_path *queue, int **cord);
int		push(t_path *queue, int x, int y);
int		get_queue_size(t_path *queue);

int		calc_gap_tile(int tile, int pos);

#endif