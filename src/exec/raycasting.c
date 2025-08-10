/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:21:55 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/31 19:58:55 by SeeTwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//the bit manipulation is for extracting the sign bit of the coordinate
//(0 for positive and 1 for negative)

int	int_pow(int n, int pow)
{
	if (pow)
		return (n);
	return (1);
}

void	wall_intersection(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->dist = (ray->mapx - cub->px
				+ (1 - ray->map_step_x) / 2) / ray->rayx;
		ray->wall_column = cub->py + ray->dist * ray->rayy;
	}
	else
	{
		ray->dist = (ray->mapy - cub->py
				+ (1 - ray->map_step_y) / 2) / ray->rayy;
		ray->wall_column = cub->px + ray->dist * ray->rayx;
	}
	ray->wall_column -= floor(ray->wall_column);
}

void	ray_init(t_cub *cub, t_ray *ray, double cameraX)
{
	ray->rayx = cub->dirx + (cub->camx * cameraX);
	ray->rayy = cub->diry + (cub->camy * cameraX);
	ray->xsign = (*(long long *)&ray->rayx) >> 63 & 1;
	ray->ysign = (*(long long *)&ray->rayy) >> 63 & 1;
	ray->stepx = fabs(1.0 / ray->rayx);
	ray->stepy = fabs(1.0 / ray->rayy);
	if (ray->xsign)
		ray->distx = (cub->px - (double)ray->mapx) * ray->stepx;
	else
		ray->distx = (1.0 - (cub->px - (double)ray->mapx)) * ray->stepx;
	if (ray->ysign)
		ray->disty = (cub->py - (double)ray->mapy) * ray->stepy;
	else
		ray->disty = (1.0 - (cub->py - (double)ray->mapy)) * ray->stepy;
	ray->map_step_x = int_pow(-1, ray->xsign);
	ray->map_step_y = int_pow(-1, ray->ysign);
}

void	dda(t_cub *cub, t_ray *ray, int x)
{
	float	cam_x;

	cam_x = 1.0 - ((double)x * (2.0 / WIN_W));
	ray_init(cub, ray, cam_x);
	while (cub->map->map[ray->mapy][ray->mapx] != '1')
	{
		if (ray->rayx && ray->distx < ray->disty)
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
	wall_intersection(cub, ray);
}

void	raycasting(t_cub *cub)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_W)
	{
		ray.mapx = (int)cub->px;
		ray.mapy = (int)cub->py;
		dda(cub, &ray, x);
		fill_column(cub, ray, x);
		x++;
	}
}

/*
after we get the position and angle of the player with the hooks, we compute a 
dir vector and a camera plane vector

using those vector we can compute the vectors of all the rays we need 
to render the screen

for every ray, we dda which is looking at every new tile the ray encounters 
if the tile has a wall in it. 

when we find the wall we calculate the coordinates of the intersection 
between the ray and the wall, which will give us the vertical 
column of the texture to render

we also need to determine the orientation of the wall we hit so we 
know which texture to apply

and we need to compute the length of the ray between the player position 
and the wall so we can scale the wall on the screen appropriately
*/
