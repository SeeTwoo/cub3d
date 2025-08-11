/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:48:42 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/11 16:18:55 by SeeTwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init(t_cub *cub)
{
	cub->mlx_win = mlx_new_window(cub->mlx, WIN_W, WIN_H, "Cub3d");
	if (cub->mlx_win == NULL)
		return (0);
	cub->img.img = mlx_new_image(cub->mlx, WIN_W, WIN_H);
	if (!cub->img.img)
		return (error(cub));
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpx,
			&cub->img.ln_len, &cub->img.endn);
	if (!cub->img.addr)
		return (error(cub));
	cub->speed = 0;
	cub->lateral_speed = 0;
	cub->rotation_speed = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*info;

	if (argc < 2)
		return (error_message("Need arguments\n"));
	info = malloc(sizeof(t_cub));
	if (!info)
		return (0);
	if (!init_cub(info))
		return (free(info), 0);
	if (!parsing(argc, argv, info))
		return (free_clean(info), 0);
	init(info);
	set_hooks(info);
	mlx_loop(info->mlx);
	free_all(info);
	return (1);
}
