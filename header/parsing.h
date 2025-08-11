/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:02:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/11 12:21:09 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structure.h"

//  ---parsing.c --- //
int		parsing(int argc, char **argv, t_cub *info);
//  ---parsing.c --- //

//  --- verif_pre_open.c --- //
int		verif_pre_open(int argc, char **argv);
int		nb_arg(int nb);
int		end_with_cub(char *argv);
//  ---verif_pre_open.c --- //

//  --- open_file.c --- //
int		open_file(char *path, t_cub *info);
//  --- open_file.c --- //

//  --- file_is_valid.c --- //
int		file_is_valid(t_cub *info);
//  --- file_is_valid.c --- //

//  --- line_is_valid.c --- //
int		setup_valid(t_cub *info);
//  --- line_is_valid.c --- //

//  --- get_color.c --- //
int		get_color_pars(t_cub *info, char *str);
//  --- get_color.c --- //

//  --- parse_map.c --- //
int		parse_map(t_cub *info, t_map *map);
//  --- parse_map.c --- //

//  --- map_is_closed.c --- //
int		map_is_closed(char **map);
//  --- map_is_closed.c --- //

//  --- reverse_map.c --- //
int		reverse_map(t_map *map_struct, char **map_origin);
//  --- reverse_map.c --- //

//  --- fill_with_one.c --- //
void	fill_with_one(char **map, t_map *map_info);
//  --- fill_with_one.c --- //

//  --- get_pos_player.c --- //
void	get_pos_player(t_cub *info, char **map);
//  --- get_pos_player.c --- //

//  --- add_map_line.c --- //
int		add_map_line(t_link_map **head, t_link_map **current, char *str);
//  --- add_map_line.c --- //

#endif
