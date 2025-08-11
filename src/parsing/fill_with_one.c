/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_with_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:23:03 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/11 12:31:54 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_with_one(char **map, t_map *map_info)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < map_info->map_height)
	{
		i = 0;
		while (i < map_info->map_width - 1)
		{
			if (map[j][i] == ' ' || map[j][i] == '\n')
				map[j][i] = '1';
			i++;
		}
		j++;
	}
}
