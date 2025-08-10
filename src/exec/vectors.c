/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 05:55:52 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/30 13:57:18 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//pi / 180 is for degrees to radians conversion

void	vectors(t_cub *cub)
{
	cub->dirx = sin((PI / 180) * cub->pangle);
	cub->diry = cos((PI / 180) * cub->pangle);
	cub->camx = -cub->diry * 1.1;
	cub->camy = cub->dirx * 1.1;
}
