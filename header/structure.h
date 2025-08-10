/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:45:32 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 10:35:51 by SeeTwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_cub	t_cub;
typedef int				(*t_keyboard_func)(t_cub *cub);

typedef struct s_text
{
	void	*img_ptr;
	char	*addr;
	int		bpx;
	int		ln_len;
	int		endn;
	int		img_width;
	int		img_height;
}	t_text;

typedef struct s_map
{
	size_t		map_width;
	size_t		map_height;
	char		**map;
}					t_map;

typedef struct s_link_map
{
	int			x;
	int			y;
	char		*value;
	struct s_link_map	*next;
}					t_link_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpx;
	int		ln_len;
	int		endn;
}				t_data;

typedef struct s_column
{
	t_text	*text;
	int		wall_height;
	int		ceiling_height;
	int		text_x;
	int		text_y;
} t_column;

struct s_cub
{
	t_text			*north;
	t_text			*south;
	t_text			*east;
	t_text			*west;
	t_map			*map;
	t_data			img;
	int				fd_map;
	int				color_floor;
	int				color_ceilling;
	void			*mlx;
	void			*mlx_win;
	char			*str;
	double			px;
	double			py;
	int				pangle;
	double			dirx;
	double			diry;
	double			camx;
	double			camy;
	t_keyboard_func	keyboard_funcs[65364];
};

typedef struct s_ray
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
}				t_ray;


#endif
