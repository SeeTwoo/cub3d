/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:56:07 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 16:21:26 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	set_p_angle(char **map, int row, int col)
{
	if (map[row][col] == 'N')
		return (0);
	if (map[row][col] == 'E')
		return (90);
	if (map[row][col] == 'S')
		return (180);
	return (360);
}

void	get_pos_player(t_cub *info, char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] != '1' && map[row][col] != '0'
				&& map[row][col] != '\n')
			{
				info->px = col + 0.5;
				info->py = row + 0.5;
				info->pangle = set_p_angle(map, row, col);
				return ;
			}
			col++;
		}
		row++;
	}
}
