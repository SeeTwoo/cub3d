/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <seetwoo@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:34:23 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/25 14:00:32 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rotation(int keycode, t_cub *cub)
{
	if (keycode == RIGHT)
		cub->pangle++;
	if (keycode == LEFT)
		cub->pangle--;
	ft_bzero(cub->img.addr, WIN_W * WIN_H * (cub->img.bpx / 8));
	vectors(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
	return (0);
}

void	set_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx_win, 2, 1, rotation, cub);
}
