/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:50:22 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 16:17:58 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	reverse_map(t_map *map, char **map_patern)
{
	int		row;
	int		row_bis;
	char	*tmp;

	row = 0;
	row_bis = map->map_height - 1;
	while (row < row_bis)
	{
		tmp = map_patern[row];
		map_patern[row] = map_patern[row_bis];
		map_patern[row_bis] = tmp;
		row++;
		row_bis--;
	}
	return (1);
}
