/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:37:17 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/25 13:43:04 by seetwoo          ###   ########.fr       */
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
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIN_W, WIN_H, "cub3d");
	cub->img.img = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpx,
				&cub->img.ln_len, &cub->img.endn);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (0);
//	temp_text_init(&cub);
	crash_init(&cub, ft_atoi(av[1]));
	vectors(&cub);
	raycasting(&cub);
	mlx_put_image_to_window(cub.mlx, cub.mlx_win, cub.img.img, 0, 0);
	set_hooks(&cub);
	mlx_loop(cub.mlx);
}
