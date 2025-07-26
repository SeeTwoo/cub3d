/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:46:15 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/26 19:47:24 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
