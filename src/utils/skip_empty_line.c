/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_empty_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:39:10 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 14:09:36 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_empty_line(t_cub *info)
{
	while (info->str[0] == '\n')
	{
		free(info->str);
		info->str = get_next_line(info->fd_map);
		if (!info->str)
			return (0);
	}
	return (info->str);
}
