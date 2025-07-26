/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:53:18 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/26 17:40:47 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FUNC_H
# define CUB_FUNC_H

int		error(t_cub *cub);
void	fill_column(t_cub *cub, t_ray ray, int x);
void	free_all(t_cub *cub);
void	raycasting(t_cub *cub);
void	set_hooks(t_cub *cub);
void	vectors(t_cub *cub);

#endif
