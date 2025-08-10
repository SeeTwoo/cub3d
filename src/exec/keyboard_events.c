/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:37:27 by wbeschon          #+#    #+#             */
/*   Updated: 2025/08/10 17:54:27 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#ifndef ROT_STEP
# define ROT_STEP 2
#endif

int	rotate_left(t_cub *cub)
{
	cub->pangle -= ROT_STEP;
	return (0);
}

int	rotate_right(t_cub *cub)
{
	cub->pangle += ROT_STEP;
	return (0);
}

int	do_nothing(t_cub *cub)
{
	(void)cub;
	return (0);
}

int	esc(t_cub *cub)
{
	free_all(cub);
	exit(EXIT_SUCCESS);
}
