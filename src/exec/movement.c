/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:05:13 by SeeTwoo           #+#    #+#             */
/*   Updated: 2025/08/11 16:02:53 by SeeTwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef ROT
# define ROT 2
#endif

#ifndef SPEED
# define SPEED 0.0537643
#endif

int	advance(t_cub *cub)
{
	double	new_x;
	double	new_y;

	if (cub->speed == 0)
		return (0);
	new_x = cub->px + (cub->dirx * (double)cub->speed * SPEED);
	new_y = cub->py + (cub->diry * (double)cub->speed * SPEED);
	if (cub->map->map[(int)new_y][(int)new_x] == '1')
		return (1);
	cub->px = new_x;
	cub->py = new_y;
	return (0);
}

int	strafe(t_cub *cub)
{
	double	new_x;
	double	new_y;

	if (cub->lateral_speed == 0)
		return (0);
	new_x = cub->px - (cub->diry * cub->lateral_speed * SPEED);
	new_y = cub->py + (cub->dirx * cub->lateral_speed * SPEED);
	if (cub->map->map[(int)new_y][(int)new_x] == '1')
		return (1);
	cub->px = new_x;
	cub->py = new_y;
	return (0);
}

int	movement(t_cub *cub)
{
	cub->pangle -= ROT * cub->rotation_speed;
	advance(cub);
	strafe(cub);
	return (0);
}
