/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:05:38 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 14:31:51 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	close_mlx(t_cub *info)
{
	if (info->north->img_ptr)
		mlx_destroy_image(info->mlx, info->north->img_ptr);
	free(info->north);
	if (info->south->img_ptr)
		mlx_destroy_image(info->mlx, info->south->img_ptr);
	free(info->south);
	if (info->east->img_ptr)
		mlx_destroy_image(info->mlx, info->east->img_ptr);
	free(info->east);
	if (info->west->img_ptr)
		mlx_destroy_image(info->mlx, info->west->img_ptr);
	free(info->west);
}
