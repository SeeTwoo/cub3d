/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:15:00 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 14:04:02 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	open_file(char *path, t_cub *info)
{
	info->fd_map = open(path, O_RDONLY);
	if (info->fd_map == -1)
	{
		ft_putstr_fd(path, 2);
		return (error_message(" : couldn't open file\n"));
	}
	return (1);
}
