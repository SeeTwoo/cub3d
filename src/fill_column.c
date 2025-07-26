/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <seetwoo@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:03:12 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/26 16:44:20 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pix_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->ln_len + x * (data->bpx / 8));
	*(unsigned int *)dest = color;
}

int	get_color(t_ray ray)
{
	if (ray.side == 0 && ray.rayx < 0)
		return (0x000000FF);
	if (ray.side == 0 && ray.rayx > 0)
		return (0x0000FFFF);
	if (ray.side == 1 && ray.rayy < 0)
		return (0x00F00020);
	if (ray.side == 1 && ray.rayy > 0)
		return (0x00FFFF00);
	return (0);
}

void	fill_column(t_cub *cub, t_ray ray, int x)
{
	float	wall_height;
	int		wall_color;
	int		ceiling_height;
	int		y;

	wall_height = (float)WIN_H / (ray.dist * 2.0);
	wall_color = get_color(ray);
	y = 0;
	ceiling_height = (WIN_H - (int)wall_height) / 2;
	while (y < ceiling_height)
	{
		//pix_put(&cub->img, x, WIN_H - y - 1, 0x00FFD700);
//		pix_put(&cub->img, x, y, 0x00FF00FF);
		pix_put(&cub->img, x, WIN_H - y - 1, 0x00808080);
		pix_put(&cub->img, x, y, 0x00F0F0F0);
		y++;
	}
	while (y <= WIN_H / 2)
	{
		pix_put(&cub->img, x, WIN_H - y - 1, wall_color);
		pix_put(&cub->img, x, y, wall_color);
		y++;
	}
}
