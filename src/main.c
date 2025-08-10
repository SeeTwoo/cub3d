/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:48:42 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 16:13:19 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init(t_cub *cub)
{
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

int	main(int argc, char **argv)
{
	t_cub	*info;
	int		i;
	int		row;

	if (argc < 2)
		return (error_message("Need arguments\n"));
	i = 0;
	row = 0;
	info = malloc(sizeof(t_cub));
	if (!info)
		return (0);
	if (!init_cub(info))
		return (free(info), 0);
	if (!parsing(argc, argv, info))
		return (free_clean(info), 0);
	init(info);
	new_frame(info);
	set_hooks(info);
	mlx_loop(info->mlx);
	free_all(info);
	return (1);
}
