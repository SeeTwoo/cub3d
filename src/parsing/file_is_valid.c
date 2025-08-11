/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:01:15 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 14:18:54 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_is_valid(t_cub *info)
{
	if (!setup_valid(info))
	{
		if (info->fd_map != -1)
			close_fd(&info->fd_map);
		return (0);
	}
	return (1);
}
