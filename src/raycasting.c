/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:21:55 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/10 21:06:10 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycasting(t_cub *cub)
{
	t_ray	ray;

	compute_raydir(cub, &ray, 0);
	dda(cub, &ray);
}

/*
after we get the position and angle of the player with the hooks, we compute a 
dir vector and a camera plane vector

using those vector we can compute the vectors of all the rays we need to render the screen

for every ray, we dda which is looking at every new tile the ray encounters if the tile has a wall in it. 

when we find the wall we calculate the coordinates of the intersection between the ray and the wall, which will give us the vertical column of the texture to render

we also need to determine the orientation of the wall we hit so we know which texture to apply

and we need to compute the length of the ray between the player position and the wall so we can scale the wall on the screen appropriately
*/
