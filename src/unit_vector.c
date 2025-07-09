/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:55:39 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/09 02:19:40 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	deg_to_rad(int angle)\
{
	return ((PI/180) * angle);
}

void	compute_dir_vector(t_cub *cub)
{
	cub->dirx = sin(deg_to_rad(cub->pangle));
	cub->diry = cos(deg_to_rad(cub->pangle));
	printf("\ndirx = %f and diry = %f\n\n", cub->dirx, cub->diry);
}
