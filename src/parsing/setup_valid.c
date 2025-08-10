/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:02:33 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/31 19:38:13 by SeeTwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	setup_valid(t_cub *info)
{
	int		result;

	while (1)
	{
		result = 1;
		info->str = get_next_line(info->fd_map);
		if (!info->str)
			return (close_all_fd(info), 0);
		if (info->str[0] == 'N' && info->str[1] == 'O')
			result = init_text(info->north, info->mlx, info->str + 2);
		else if (info->str[0] == 'S' && info->str[1] == 'O')
			result = init_text(info->south, info->mlx, info->str + 2);
		else if (info->str[0] == 'W' && info->str[1] == 'E')
			result = init_text(info->west, info->mlx, info->str + 2);
		else if (info->str[0] == 'E' && info->str[1] == 'A')
			result = init_text(info->east, info->mlx, info->str + 2);
		else
			result = get_color_pars(info, info->str);
		if ((result == 0 && info->str[0] != '\n') || result == -1)
			return (free(info->str), 0);
		else if (result == 2)
			return (1);
		free(info->str);
	}
	return (1);
}
