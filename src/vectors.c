/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 05:55:52 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/15 07:16:59 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//pi / 180 is for degrees to radians conversion

void	vectors(t_cub *cub)
{
	cub->dirx = sin((PI / 180) * cub->pangle);
	cub->diry = cos((PI/ 180) * cub->pangle);
	cub->camx = -cub->dirx;
	cub->camy = cub->diry;
//	printf("dirx = %f and diry = %f\n\n", cub->dirx, cub->diry);
}
