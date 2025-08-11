/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:17:57 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/11 12:22:39 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structure.h"

//  --- error_mesage.c --- //
int		error_message(char *str);
int		error_message_bis(char *str, char *str2);
//  --- error_mesage.c --- //

//	--- close_all_fd.c --- //
void	close_all_fd(t_cub *info);
void	close_fd(int *fd);
//	--- close_all_fd.c --- //

//	--- init.c --- //
int		init_cub(t_cub *info);
int		open_fd(int *fd, char *str);
int		init_text(t_text *side, void *mlx, char *str);
//	--- init_fd.c --- //

//  --- close_mlx.c --- //
void	close_mlx(t_cub *info);
//  --- close_mlx.c --- //

//  --- skip_white.c --- //
int		skip_white(char *str, int i);
//  --- skip_white.c --- //

//  --- free_text.c --- //
void	free_texture(t_cub *info);
//  --- free_text.c --- //

//  --- free_linked_list.c --- //
void	free_node(t_link_map *node);
//  --- free_linked_list.c --- //

//  --- free_clean.c --- //
void	free_clean(t_cub *info);
//  --- free_clean.c --- //

//  --- skip_empty_line.c --- //
char	*skip_empty_line(t_cub *info);
//  --- skip_empty_line.c --- //

#endif
