/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 05:55:52 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/26 13:16:45 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//pi / 180 is for degrees to radians conversion

void	vectors(t_cub *cub)
{
	cub->dirx = sin((PI / 180) * cub->pangle);
	cub->diry = cos((PI/ 180) * cub->pangle);
	cub->camx = -cub->diry * 1.1;
	cub->camy = cub->dirx * 1.1;
}
