/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:58:02 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/04 23:04:58 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

fill_text(int text[64][64], int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			text[i][j] = color;
			j++;
		}
		i++;
	}
}

void	init_temp_text(t_cub *cub)
{
	fill_text(cub->west_text, BLUE);
	fill_text(cub->east_text, ORANGE);
	fill_text(cub->north_text, YELLOW);
	fill_text(cub->south_text, CYAN);
}
