/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:52:15 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 14:08:54 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_cub *info)
{
	if (info->north)
		free(info->north);
	if (info->south)
		free(info->south);
	if (info->east)
		free(info->east);
	if (info->west)
		free(info->west);
}
