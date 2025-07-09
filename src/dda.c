/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:05:31 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/09 04:45:45 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_sign(double n)
{
	return (*(long long *)&n >> 63 & 1);
}

int	get_closest_border(int coor_sign, int player_pos)
{
	return ((player_pos - (player_pos % 64)) + (64 * (1 - coor_sign)));
}

int	ratio_diff(t_ray *ray)
{
	return (ray->off_x / ray->off_y < ray->raydirx / ray->raydiry);
}

int	wall_hit(t_cub *cub, t_ray *ray)
{
	int	i;
	int	j;

	i = ray->y_edge / 64;
	j = ray->x_edge / 64;
	printf("x edge is %d and y edge is %d\ni is %d and j is %d\n", ray->x_edge, ray->y_edge, i, j);
	printf("off_x = %d and off_y = %d\n\n", ray->off_x, ray->off_y);
	if ((ray->raydirx == 0 || ray->ratio_diff)
			&& cub->map[i - (2 * ray->y_sign)][j] == '1')
		return (1);
	if ((ray->raydiry == 0 || !ray->ratio_diff)
			&& cub->map[i][j - (2 * ray->x_sign)] == '1')
		return (1);
	return (0);
}

void	dda(t_cub *cub, t_ray *ray)
{
	int	i;

	i = 0;
	ray->x_sign = get_sign(ray->raydirx);
	ray->y_sign = get_sign(ray->raydiry);
	ray->x_edge = get_closest_border(ray->x_sign, cub->px);
	ray->y_edge = get_closest_border(ray->y_sign, cub->py);
	ray->off_x = cub->px - ray->x_edge;
	ray->off_y = cub->py - ray->y_edge;
	ray->ratio_diff = ratio_diff(ray);
	printf("player is at x = %d and y = %d\nclosest borders are x = %d and y %d\n",
			cub->px, cub->py, ray->x_edge, ray->y_edge);
	printf("pangle is %d, ray x = %f ray y = %f\n\n", cub->pangle, ray->raydirx, ray->raydiry);
	while (wall_hit(cub, ray) == 0 && i < 10)
	{
		if (ray->raydirx == 0 || ray->ratio_diff)
			ray->y_edge += 64 * (1 - (2 * ray->y_sign));
		else
			ray->x_edge += 64 * (1 - (2 * ray->x_sign)); 
		ray->off_x = cub->px - ray->x_edge;
		ray->off_y = cub->py - ray->y_edge;
		ray->ratio_diff = ratio_diff(ray);
		i++;
	}
	printf("wall is x = %d and y = %d\n", ray->x_edge, ray->y_edge);
}
