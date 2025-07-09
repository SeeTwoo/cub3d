/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:48:27 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/09 01:13:01 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct s_cub	t_cub;
typedef struct s_data	t_data;
typedef struct s_ray	t_ray;

/*
px is player x position
py is player y position
pangle is the player angle;
dirx is the x component of the unit direction vector;
diry is the y component of the unit direction vector;
camerax is the x component of the camera plane
cameray is the y component of the camera plane
*/

struct s_cub
{
	char	map[64][64];
	char	textures_files[4][256];
	int		west_text[64][64];
	int		north_text[64][64];
	int		east_text[64][64];
	int		south_text[64][64];
	t_data	*img;
	void	*mlx;
	void	*mlx_win;
	int		px;
	int		py;
	int		pangle;
	double	dirx;
	double	diry;
	double	camplanex;
	double	camplaney;
};

struct s_ray
{
	double	raydirx;
	double	raydiry;
	int		x_sign;
	int		y_sign;
	int		x_edge;
	int		y_edge;
	int		wall_x;
	int		wall_y;
	int		off_x;
	int		off_y;
	int		ratio_diff;
};

struct s_data
{
	void	*img;
	char	*addr;
	int		bpx;
	int		ln_len;
	int		endn;
};

#endif
