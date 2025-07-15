/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:21:55 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/15 07:39:02 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//the bit manipulation is for extracting the sign bit of the coordinate
//(0 for positive and 1 for negative)

int	int_pow(int n, int pow)
{
	if (pow)
		return (n);
	return (1);
}

void	ray_init(t_cub *cub, t_ray *ray, double cameraX)
{
	ray->rayx = cub->dirx + (cub->camx * cameraX);
	ray->rayy = cub->diry + (cub->camy * cameraX);
	ray->xsign = (*(long long *)&ray->rayx) >> 63 & 1;
	ray->ysign = (*(long long *)&ray->rayy) >> 63 & 1;
	ray->mapx = (int)cub->px;
	ray->mapy = (int)cub->py;
	if (ray->xsign)
		ray->distx = (cub->px - ray->mapx) * ray->rayx;
	else
		ray->distx = (1.0 - (cub->px - ray->mapx)) * ray->rayx;
	if (ray->ysign)
		ray->disty = (cub->py - ray->mapy) * ray->rayy;
	else
		ray->disty = (1.0 - (cub->py - ray->mapy)) * ray->rayy;
	ray->stepx = fabs(1 / ray->rayx);
	ray->stepy = fabs(1 / ray->rayy);
	ray->map_step_x = int_pow(-1, ray->xsign);
	ray->map_step_y = int_pow(-1, ray->ysign);
}

void	dda(t_cub *cub, t_ray *ray, double cameraX)
{
	ray_init(cub, ray, cameraX);
	while (cub->map[ray->mapy][ray->mapx] != '1')
	{
		if (ray->distx < ray->disty)
		{
			ray->distx += ray->stepx;
			ray->mapx += ray->map_step_x;
			ray->side = 0;
		}
		else
		{
			ray->disty += ray->stepy;
			ray->mapy += ray->map_step_y;
			ray->side = 1;
		}
	}
	printf("hit the %d, %d wall\n", ray->mapx, ray->mapy);
}

void	raycasting(t_cub *cub)
{
	t_ray	ray;

	dda(cub, &ray, 0);
}

/*
after we get the position and angle of the player with the hooks, we compute a 
dir vector and a camera plane vector

using those vector we can compute the vectors of all the rays we need to render the screen

for every ray, we dda which is looking at every new tile the ray encounters if the tile has a wall in it. 

when we find the wall we calculate the coordinates of the intersection between the ray and the wall, which will give us the vertical column of the texture to render

we also need to determine the orientation of the wall we hit so we know which texture to apply

and we need to compute the length of the ray between the player position and the wall so we can scale the wall on the screen appropriately
*/
