/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:46:15 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/30 13:57:06 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_keyboard_funcs(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 65364)
		cub->keyboard_funcs[i] = do_nothing;
	cub->keyboard_funcs[W] = forward;
	cub->keyboard_funcs[A] = strafe_left;
	cub->keyboard_funcs[S] = backward;
	cub->keyboard_funcs[D] = strafe_right;
	cub->keyboard_funcs[LEFT] = rotate_left;
	cub->keyboard_funcs[RIGHT] = rotate_right;
	cub->keyboard_funcs[ESC] = esc;
	return (0);
}
