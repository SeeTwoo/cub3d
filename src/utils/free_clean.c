/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:24:34 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 14:43:55 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_clean(t_cub *cub)
{
	close_mlx(cub);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	if (cub->map->map)
		free_tab(cub->map->map);
	free(cub->map);
	free(cub->mlx);
	free(cub);
}
