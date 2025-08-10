/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:34:23 by seetwoo           #+#    #+#             */
/*   Updated: 2025/08/10 16:22:28 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keyb_input(int keycode, t_cub *cub)
{
	if (keycode < 0 || keycode > 65363)
	{
		printf("out of bounds keycode \n");
		return (1);
	}
	cub->keyboard_funcs[keycode](cub);
	return (0);
}

void	set_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx_win, 2, 1, keyb_input, cub);
}
