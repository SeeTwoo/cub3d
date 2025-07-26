/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:32:50 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/26 17:45:43 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_all(t_cub *cub)
{
	if (cub->img.img)
		mlx_destroy_image(cub->mlx, cub->img.img);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->mlx);
}

int	error(t_cub *cub)
{
	(void)cub;
	free_all(cub);
	exit(EXIT_FAILURE);
}
