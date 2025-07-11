/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:53:18 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/10 18:22:35 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FUNC_H
# define CUB_FUNC_H

void	compute_camera_plane(t_cub *cub);
void	compute_dir_vector(t_cub *cub);
void	compute_raydir(t_cub *cub, t_ray *ray, double cameraX);
void	dda(t_cub *cub, t_ray *ray);
void	get_next_tiles(t_ray *ray);
int		int_pow(int n, int pow);
void	print_data(t_cub *cub, t_ray *ray);
void	raycasting(t_cub *cub);
int		tan_diff(t_ray *ray);

#endif
