/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:16:36 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/10 18:24:10 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_data(t_cub *cub, t_ray *ray)
{
	(void)cub;
	printf("raydir x = %f\n", ray->raydirx);
	printf("raydir y = %f\n", ray->raydiry);
	printf("ray x sign = %d\n", ray->x_sign);
	printf("ray y sign = %d\n", ray->y_sign);
	printf("x tile = %d\n", ray->x_edge);
	printf("y tile = %d\n", ray->y_edge);
	printf("x corner = %d\n", ray->off_x);
	printf("y corner = %d\n", ray->off_y);
	printf("i = %d\n", ray->i);
	printf("j = %d\n", ray->j);
}
