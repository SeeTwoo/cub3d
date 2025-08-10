/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:56:07 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 17:58:19 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			if (map[row][col] != '1' && map[row][col] != '0' && map[row][col] != '\n')
			{
				info->px = col + 0.5;
				info->py = row + 0.5;
				if (map[row][col] == 'N')
					info->pangle = 0;
				if (map[row][col] == 'E')
					info->pangle = 90;
				if (map[row][col] == 'S')
					info->pangle = 180;
				if (map[row][col] == 'W')
					info->pangle = 270;
				return ;
			}
			col++;
		}
		row++;
	}
}
