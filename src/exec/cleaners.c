/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:32:50 by wbeschon          #+#    #+#             */
/*   Updated: 2025/08/10 14:42:56 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_all(t_cub *cub)
{
	close_mlx(cub);
	if (cub->img.img)
		mlx_destroy_image(cub->mlx, cub->img.img);
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

int	error(t_cub *cub)
{
	(void)cub;
	free_all(cub);
	exit(EXIT_FAILURE);
}
