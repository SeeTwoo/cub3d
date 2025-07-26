/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:53:18 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/25 13:42:23 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FUNC_H
# define CUB_FUNC_H

void	fill_column(t_cub *cub, t_ray ray, int x);
void	raycasting(t_cub *cub);
void	set_hooks(t_cub *cub);
void	vectors(t_cub *cub);

#endif
