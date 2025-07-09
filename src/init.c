/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:46:15 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/05 16:54:51 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	null_all(t_cub *cub)
{
	cub->img.img = NULL;
	cub->img.addr = NULL;
	cub->mlx = NULL;
	cub->mlx_win = NULL;
}

void	init(t_cub *cub)
{
	null_all(cub);
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_nuw_window(cub->mlx, WIN_W, WIN_H, "cub3d");
	cub->img.img = mlx_nuw_image(cub->mlx, WIN_H, WIN_H);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->mig.bpx,
			&cub->img.ln_len,, &cub->img.endn);
	temp_init_text(cub);
}
