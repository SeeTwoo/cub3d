/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:37:17 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/15 05:51:46 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	crash_init(t_cub *cub, int angle)
{
	ft_memcpy(cub->map[0], "11111", 5);
	ft_memcpy(cub->map[1], "10001", 5);
	ft_memcpy(cub->map[2], "10001", 5);
	ft_memcpy(cub->map[3], "10001", 5);
	ft_memcpy(cub->map[4], "11111", 5);
	cub->px = 2.5;
	cub->py = 2.5;
	cub->pangle = angle;
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (0);
//j	init(t_cub *cub);
//	temp_text_init(&cub);
//	mlx_put_image_to_window(arg.mlx, arg.mlx_win, arg.img.img, 0, 0);
//	mlx_loop(arg.mlx);
	crash_init(&cub, ft_atoi(av[1]));
	vectors(&cub);
	raycasting(&cub);
}
