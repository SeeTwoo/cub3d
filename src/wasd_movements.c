/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:37:00 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/26 19:58:15 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#ifndef SPEED
# define SPEED 0.05
#endif

int	forward(t_cub *cub)
{
	double	newx;
	double	newy;

	newx = cub->px + (cub->dirx * SPEED);
	newy = cub->py + (cub->diry * SPEED);
	if (cub->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	return (new_frame(cub));
}

int	backward(t_cub *cub)
{
	double	newx;
	double	newy;

	newx = cub->px - (cub->dirx * SPEED);
	newy = cub->py - (cub->diry * SPEED);
	if (cub->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	return (new_frame(cub));
}

int	strafe_left(t_cub *cub)
{
	double	newx;
	double	newy;

	newx = cub->px - (cub->diry * SPEED);
	newy = cub->py + (cub->dirx * SPEED);
	if (cub->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	return (new_frame(cub));
}

int	strafe_right(t_cub *cub)
{
	double	newx;
	double	newy;

	newx = cub->px + (cub->diry * SPEED);
	newy = cub->py - (cub->dirx * SPEED);
	if (cub->map[(int)newy][(int)newx] == '1')
		return (1);
	cub->px = newx;
	cub->py = newy;
	return (new_frame(cub));
}
