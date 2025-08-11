/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:34:23 by seetwoo           #+#    #+#             */
/*   Updated: 2025/08/11 14:51:50 by SeeTwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	esc(t_cub *cub)
{
	free_all(cub);
	exit(EXIT_SUCCESS);
}

int	on_key_press(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->speed = 1;
	else if (keycode == A)
		cub->lateral_speed = 1;
	else if (keycode == S)
		cub->speed = -1;
	else if (keycode == D)
		cub->lateral_speed = -1;
	else if (keycode == LEFT)
		cub->rotation_speed = 1;
	else if (keycode == RIGHT)
		cub->rotation_speed = -1;
	else if (keycode == ESC)
		esc(cub);
	return (0);
}

int	on_key_release(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->speed = 0;
	else if (keycode == A)
		cub->lateral_speed = 0;
	else if (keycode == S)
		cub->speed = 0;
	else if (keycode == D)
		cub->lateral_speed = 0;
	else if (keycode == LEFT)
		cub->rotation_speed = 0;
	else if (keycode == RIGHT)
		cub->rotation_speed = 0;
	return (0);
}

void	set_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx_win, 2, 1, on_key_press, cub);
	mlx_hook(cub->mlx_win, 3, 2, on_key_release, cub);
	mlx_hook(cub->mlx_win, 17, 0, esc, cub);
	mlx_loop_hook(cub->mlx, new_frame, cub);
}
