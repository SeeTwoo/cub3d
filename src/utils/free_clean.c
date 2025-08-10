/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:24:34 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 14:08:48 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_clean(t_cub *info)
{
	close_mlx(info);
	if (info->map->map)
		free_tab(info->map->map);
	free(info->map);
	free(info);
}
