/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:31:26 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/06 03:56:29 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	compute_camera_plane(t_cub *cub)
{
	cub->camplanex = 0.6 * cub->diry;
	cub->camplaney = 0.6 * -cub->dirx;
}
