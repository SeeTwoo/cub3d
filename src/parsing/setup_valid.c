/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:02:33 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 16:20:54 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	test(t_cub *info, int i)
{
	if (info->str[i] == 'N' && info->str[i + 1] == 'O')
		return (init_text(info->north, info->mlx, info->str + 2 + i));
	else if (info->str[i] == 'S' && info->str[i + 1] == 'O')
		return (init_text(info->south, info->mlx, info->str + 2 + i));
	else if (info->str[i] == 'W' && info->str[i + 1] == 'E')
		return (init_text(info->west, info->mlx, info->str + 2 + i));
	else if (info->str[i] == 'E' && info->str[i + 1] == 'A')
		return (init_text(info->east, info->mlx, info->str + 2 + i));
	return (get_color_pars(info, info->str));
}

int	setup_valid(t_cub *info)
{
	int		result;
	int		i;

	while (1)
	{
		i = 0;
		result = 1;
		info->str = get_next_line(info->fd_map);
		if (!info->str)
			return (close_all_fd(info), 0);
		i = skip_white(info->str, i);
		result = test(info, i);
		if ((result == -1 && info->str[0] != '\n') || result == 0)
			return (free(info->str), 0);
		else if (result == 2)
			return (1);
		free(info->str);
	}
	return (1);
}
