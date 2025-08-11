/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:24:34 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/11 13:05:32 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_clean(t_cub *cub)
{
	close_mlx(cub);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	if (cub->map->map)
		free_tab(cub->map->map);
	free(cub->map);
	free(cub->mlx);
	free(cub);
}
