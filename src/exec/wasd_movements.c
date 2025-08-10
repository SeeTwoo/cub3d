/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:37:00 by wbeschon          #+#    #+#             */
/*   Updated: 2025/08/10 17:47:50 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#ifndef SPEED
# define SPEED 0.0487234
#endif

int	forward(t_cub *cub)
{
	double	newx;
	double	newy;

	newx = cub->px + (cub->dirx * SPEED);
	newy = cub->py + (cub->diry * SPEED);
	if (cub->map->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	return (0);
}

int	backward(t_cub *cub)
{
	double	newx;
	double	newy;

	newx = cub->px - (cub->dirx * SPEED);
	newy = cub->py - (cub->diry * SPEED);
	if (cub->map->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	return (0);
}

int	strafe_left(t_cub *cub)
{
	double	newx;
	double	newy;

	newx = cub->px - (cub->diry * SPEED);
	newy = cub->py + (cub->dirx * SPEED);
	if (cub->map->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	return (0);
}

int	strafe_right(t_cub *cub)
{
	double	newx;
	double	newy;

	newx = cub->px + (cub->diry * SPEED);
	newy = cub->py - (cub->dirx * SPEED);
	if (cub->map->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	return (0);
}
