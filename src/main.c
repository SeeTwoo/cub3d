/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:37:17 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/27 10:29:19 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init(t_cub *cub, int angle)
{
	ft_memcpy(cub->map[4], "1111111111", 10);
	ft_memcpy(cub->map[3], "1001000001", 10);
	ft_memcpy(cub->map[2], "1000111101", 10);
	ft_memcpy(cub->map[1], "1000000001", 10);
	ft_memcpy(cub->map[0], "1111111111", 10);
	cub->px = 2.5;
	cub->py = 2.5;
	cub->pangle = angle;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (error(cub));
	cub->mlx_win = mlx_new_window(cub->mlx, WIN_W, WIN_H, "cub3d");
	if (!cub->mlx_win)
		return (error(cub));
	cub->img.img = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	if (!cub->img.img)
		return (error(cub));
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpx,
			&cub->img.ln_len, &cub->img.endn);
	if (!cub->img.addr)
		return (error(cub));
	init_keyboard_funcs(cub);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (0);
	init(&cub, ft_atoi(av[1]));
	new_frame(&cub);
	set_hooks(&cub);
	mlx_loop(cub.mlx);
}
