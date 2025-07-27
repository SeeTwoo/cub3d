/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:48:27 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/27 10:20:16 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct s_cub	t_cub;
typedef struct s_data	t_data;
typedef struct s_ray	t_ray;
typedef int				(*t_keyboard_func)(t_cub *cub);

struct s_data
{
	void	*img;
	char	*addr;
	int		bpx;
	int		ln_len;
	int		endn;
};
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
	char			map[64][64];
	char			textures_files[4][256];
	int				west_text[64][64];
	int				north_text[64][64];
	int				east_text[64][64];
	int				south_text[64][64];
	t_data			img;
	void			*mlx;
	void			*mlx_win;
	double			px;
	double			py;
	int				pangle;
	double			dirx;
	double			diry;
	double			camx;
	double			camy;
	t_keyboard_func	keyboard_funcs[65364];
};

//side is a status varibable to know if the wall was 
//horizontal (0) or vertical (1);
struct s_ray
{
	double	rayx;
	double	rayy;
	int		xsign;
	int		ysign;
	double	distx;
	double	disty;
	double	stepx;
	double	stepy;
	int		mapx;
	int		mapy;
	int		map_step_x;
	int		map_step_y;
	int		side;
	double	dist;
	double	wall_column;
};

#endif
