/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:48:27 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/04 23:06:51 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct s_cub	t_cub;
typedef struct s_data	t_data;

struct s_cub
{
	char	map[64][64];
	char	textures_files[4][256];
	int		west_text[64][64];
	int		north_text[64][64];
	int		east_text[64][64];
	int		south_text[64][64];
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		direction[vec
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
