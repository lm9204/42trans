/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:35:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/17 08:14:18 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	get_sprite_size(char *file_path)
{
	char	*line;
	int		size;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	return (size);
}
