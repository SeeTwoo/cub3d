/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:53:28 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 16:17:51 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int argc, char **argv, t_cub *info)
{
	if (!verif_pre_open(argc, argv))
		return (0);
	if (!open_file(argv[1], info))
		return (0);
	if (!file_is_valid(info))
		return (0);
	if (!info->west->img_ptr || !info->north->img_ptr
		|| !info->south->img_ptr || !info->east->img_ptr)
		return (free(info->str), error_message("Missing texture\n"));
	if (!parse_map(info, info->map))
		return (0);
	if (!map_is_closed(info->map->map))
		return (0);
	if (!reverse_map(info->map, info->map->map))
		return (0);
	fill_with_one(info->map->map, info->map);
	get_pos_player(info, info->map->map);
	return (1);
}
