/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:37:17 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/04 22:46:07 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(void)
{
	t_cub	cub;

	init(t_cub *cub);
	temp_text_init(&cub);
	mlx_put_image_to_window(arg.mlx, arg.mlx_win, arg.img.img, 0, 0);
	mlx_loop(arg.mlx);
}
