/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:37:17 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/26 17:47:10 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init(t_cub *cub, int angle)
{
	ft_memcpy(cub->map[0], "11111", 5);
	ft_memcpy(cub->map[1], "10011", 5);
	ft_memcpy(cub->map[2], "10001", 5);
	ft_memcpy(cub->map[3], "10001", 5);
	ft_memcpy(cub->map[4], "11111", 5);
	cub->px = 2.5;
	cub->py = 2.5;
	cub->pangle = angle;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (error(cub));
	cub->mlx_win = mlx_new_window(cub->mlx, WIN_W, WIN_H, "cub3d");
	if (!cub->mlx_win)
		return (error(cub));
	cub->img.img = NULL; //mlx_new_image(cub->mlx, WIN_W, WIN_H);
	if (!cub->img.img)
		return (error(cub));
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpx,
				&cub->img.ln_len, &cub->img.endn);
	if (!cub->img.addr)
		return (error(cub));
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (0);
//	temp_text_init(&cub);
	init(&cub, ft_atoi(av[1]));
	vectors(&cub);
	raycasting(&cub);
	mlx_put_image_to_window(cub.mlx, cub.mlx_win, cub.img.img, 0, 0);
	set_hooks(&cub);
	mlx_loop(cub.mlx);
}
