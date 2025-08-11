/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:03:12 by seetwoo           #+#    #+#             */
/*   Updated: 2025/08/11 15:47:12 by SeeTwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pix_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->ln_len + x * (data->bpx / 8));
	*(unsigned int *)dest = color;
}

t_text	*get_text(t_ray ray, t_cub *cub)
{
	if (ray.side == 0 && ray.rayx < 0)
		return (cub->east);
	if (ray.side == 0 && ray.rayx > 0)
		return (cub->west);
	if (ray.side == 1 && ray.rayy < 0)
		return (cub->south);
	if (ray.side == 1 && ray.rayy > 0)
		return (cub->north);
	printf("no text\n");
	return (NULL);
}

int	color_in_text(t_column *column, int y)
{
	int		wall_height;
	int		ceiling_height;
	char	*addr;

	wall_height = column->wall_height;
	ceiling_height = column->ceiling_height;
	if (ceiling_height > 0)
		column->text_y = (double)((double)y / ((double)wall_height
					/ column->text->img_height));
	else
		column->text_y = (double)((double)(y - ceiling_height)
				/ ((double)wall_height / column->text->img_height));
	addr = column->text->addr + (column->text_y * column->text->ln_len
			+ column->text_x * (column->text->bpx / 8));
	return (*(unsigned int *)addr);
}

void	fill_column(t_cub *cub, t_ray ray, int x)
{
	t_column	column;
	int			y_wall;
	int			y_ceiling;
	int			screen_wall_height;

	column.wall_height = (int)((double)WIN_H / ray.dist);
	column.ceiling_height = (WIN_H - column.wall_height) / 2;
	column.text = get_text(ray, cub);
	column.text_x = (int)(ray.wall_column * (double)column.text->img_width);
	y_ceiling = 0;
	while (y_ceiling < column.ceiling_height)
	{
		pix_put(&cub->img, x, y_ceiling, cub->color_ceilling);
		pix_put(&cub->img, x, WIN_H - 1 - y_ceiling, cub->color_floor);
		y_ceiling++;
	}
	y_wall = 0;
	screen_wall_height = WIN_H - (2 * y_ceiling);
	while (y_wall < screen_wall_height)
	{
		pix_put(&cub->img, x,
			y_ceiling + y_wall,
			color_in_text(&column, y_wall));
		y_wall++;
	}
}

int	new_frame(t_cub *cub)
{
	movement(cub);
	ft_memset(cub->img.addr, 0, WIN_W * WIN_H * (cub->img.bpx / 8));
	vectors(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
	return (0);
}
