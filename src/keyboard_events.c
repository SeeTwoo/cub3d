/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:37:27 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/27 10:26:57 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#ifndef ROT_STEP
# define ROT_STEP 2
#endif

int	rotate_left(t_cub *cub)
{
	cub->pangle -= ROT_STEP;
	return (new_frame(cub));
}

int	rotate_right(t_cub *cub)
{
	cub->pangle += ROT_STEP;
	return (new_frame(cub));
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
