/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:11:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/24 20:34:14 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	init_enemy(t_obj *obj)
{
	obj->en_sprite = get_sprites(obj, M_ENEMY);
	obj->enemy = NULL;
}

void	add_enemy(t_obj *obj, int x, int y)
{
	t_enemy	*enemy;
	t_enemy	*ptr;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		handle_error(obj);
	srand((unsigned int)time(NULL));
	enemy->direction = rand() % 4;
	enemy->sprite_idx = 0;
	enemy->time = 0;
	enemy->id = x * y;
	enemy->x = x * 32;
	enemy->y = y * 32;
	enemy->path = init_path_queue(obj->map->size_x, obj->map->size_y);
	enemy->next = NULL;
	if (obj->enemy == NULL)
	{
		obj->enemy = enemy;
		return ;
	}
	ptr = obj->enemy;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = enemy;
}

void	reset_visitied(int **visited, int size_x, int size_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_y * 4)
	{
		j = 0;
		while (j < size_x * 4)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
}
