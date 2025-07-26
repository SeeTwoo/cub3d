/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <seetwoo@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:34:23 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/26 14:16:49 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#ifndef SPEED
# define SPEED 0.05
#endif

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

int	movement(int keycode, t_cub *cub)
{
	double	newx;
	double	newy;

	if (keycode == W)
	{
		newx = cub->px + (cub->dirx * SPEED);
		newy = cub->py + (cub->diry * SPEED);
	}
	else if (keycode == A)
	{
		newx = cub->px - (cub->diry * SPEED);
		newy = cub->py + (cub->dirx * SPEED);
	}
	else if (keycode == S)
	{
		newx = cub->px - (cub->dirx * SPEED);
		newy = cub->py - (cub->diry * SPEED);
	}
	else if (keycode == D)
	{
		newx = cub->px + (cub->diry * SPEED);
		newy = cub->py - (cub->dirx * SPEED);
	}
	else
		return (1);
	if (cub->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	ft_bzero(cub->img.addr, WIN_W * WIN_H * (cub->img.bpx / 8));
	vectors(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
	return (0);
}

int	keyb_input(int keycode, t_cub *cub)
{
	if (keycode == RIGHT || keycode == LEFT)
		return (rotation(keycode, cub));
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		return (movement(keycode, cub));
	printf("wrong keycode\n");
	return (0);
}

void	set_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx_win, 2, 1, keyb_input, cub);
}
