/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:02:33 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/11 13:07:13 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	test(t_cub *info)
{
	if (info->str[0] == 'N' && info->str[1] == 'O')
		return (init_text(info->north, info->mlx, info->str + 2));
	else if (info->str[0] == 'S' && info->str[1] == 'O')
		return (init_text(info->south, info->mlx, info->str + 2));
	else if (info->str[0] == 'W' && info->str[1] == 'E')
		return (init_text(info->west, info->mlx, info->str + 2));
	else if (info->str[0] == 'E' && info->str[1] == 'A')
		return (init_text(info->east, info->mlx, info->str + 2));
	return (get_color_pars(info, info->str));
}

int	setup_valid(t_cub *info)
{
	int		result;
	int		i;

	i = 0;
	while (1)
	{
		result = 1;
		info->str = get_next_line(info->fd_map);
		if (!info->str && i != 0)
			return (close_all_fd(info), 0);
		if (!info->str && i == 0)
			return (close_all_fd(info), error_message("Empty file\n"));
		result = test(info);
		if ((result == -1 && info->str[0] != '\n') || result == 0)
			return (free(info->str), 0);
		else if (result == 2)
			return (1);
		free(info->str);
		i++;
	}
	return (1);
}
