/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:03:07 by yeondcho          #+#    #+#             */
/*   Updated: 2024/02/25 12:38:22 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	calc_gap_tile(int tile, int pos)
{
	int	gap_flag;

	if ((tile + 1) * 32 - pos <= 16)
		gap_flag = 1;
	else
		gap_flag = -1;
	return (gap_flag);
}
