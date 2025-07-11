/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:05:31 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/11 04:42:59 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static inline int	get_sign(double n)
{
	return (*(long long *)&n >> 63 & 1);
}

static inline int	get_closest_border(int coor_sign, int pos)
{
	return (((pos + 1) * 64) - (64 * coor_sign));
}

int	x_or_y(t_ray *ray)
{
	double	off_tan;
	double	ray_tan;

	if (ray->raydirx)
		return (1);
	if (ray->raydiry)
		return (0);
	off_tan = (double)ray->off_x / (double)ray->off_y;
	ray_tan = ray->raydirx / ray->raydiry;
	return (off_tan > ray_tan);
}

void	ray_update(t_cub *cub, t_ray *ray)
{
	ray->x_edge = get_closest_border(ray->x_sign, ray->j);
	ray->y_edge = get_closest_border(ray->y_sign, ray->i);
	ray->off_x = ray->x_edge - cub->px;
	ray->off_y = ray->y_edge - cub->py;
	ray->x_or_y = x_or_y(ray);
}

void	ray_init(t_cub *cub, t_ray *ray)
{
	ray->x_sign = get_sign(ray->raydirx);
	ray->y_sign = get_sign(ray->raydiry);
	ray->i = cub->px / 64;
	ray->j = cub->py / 64;
	ray_update(cub, ray);
}

int	wall_hit(t_cub *cub, t_ray *ray)
{
	printf("new cycle ==========================================================\n\n");
	print_data(cub, ray);

	if (ray->x_or_y
			&& cub->map[ray->i + 1 - (2 * ray->y_sign)][ray->j] == '1')
		return (printf("vertical\n\n"), 1);
	if (!ray->x_or_y
			&& cub->map[ray->i][ray->j + 1 - (2 * ray->x_sign)] == '1')
		return (printf("horizontal\n\n"), 1);
	return (0);
}

void	dda(t_cub *cub, t_ray *ray)
{
	int	i;

	i = 0;
	ray_init(cub, ray);
	while (wall_hit(cub, ray) == 0 && i < 10)
	{
		if (ray->x_or_y)
		{
			printf("add to i\n\n");
			ray->i += 1 - (2 * ray->y_sign);
		}
		else
		{
			printf("add to j\n\n");
			ray->j += 1 - (2 * ray->x_sign); 
		}
		ray_update(cub, ray);
		i++;
	}
	printf("wall is x = %d and y = %d\n", ray->x_edge, ray->y_edge);
}
