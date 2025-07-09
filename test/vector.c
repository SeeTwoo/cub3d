/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:47:35 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/05 17:53:07 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PI
# define PI 3.14159265358979323846
#endif

double	deg_to_rad(int angle)
{
	return ((PI/180) * angle);
}

void	compute_vector(int angle, double *x, double *y)
{
	*x = cos(deg_to_rad(angle));
	*y = sin(deg_to_rad(angle));
}

int	main(int ac, char **av)
{
	double	x;
	double	y;

	if (ac != 2)
		return (1);
	compute_vector(atoi(av[1]), &x, &y);
	printf("x = %f and y = %f\n", x, y);
	return (0);
}
