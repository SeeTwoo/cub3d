/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:53:18 by seetwoo           #+#    #+#             */
/*   Updated: 2025/08/11 14:50:33 by SeeTwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FUNC_H
# define CUB_FUNC_H

int		error(t_cub *cub);
void	fill_column(t_cub *cub, t_ray ray, int x);
void	free_all(t_cub *cub);
int		new_frame(t_cub *cub);
void	raycasting(t_cub *cub);
void	set_hooks(t_cub *cub);
void	vectors(t_cub *cub);

int		movement(t_cub *cub);

int		init_keyboard_funcs(t_cub *cub);

#endif
