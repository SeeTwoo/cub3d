/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:27:18 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/07 18:36:25 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	compute_raydir(t_cub *cub, t_ray *ray, double cameraX)
{
	ray->raydirx = cub->dirx + (cub->camplanex * cameraX);
	ray->raydiry = cub->diry + (cub->camplaney * cameraX);
}
