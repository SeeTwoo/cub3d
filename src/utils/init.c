/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:13:02 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 14:17:01 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	open_fd(int *fd, char *str)
{
	int	i;

	i = 0;
	if (*fd != -1)
		return (error_message("fd already open\n"));
	while (str[i] == ' ')
		i++;
	str[ft_strlen(str) - 1] = 0;
	*fd = open(&str[i], O_RDONLY);
	if (*fd == -1)
		return (error_message_bis("can't open fd : \n", str));
	return (1);
}

int	init_mlx(t_cub *info)
{
	info->map->map = NULL;
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		return (0);
	info->mlx_win = mlx_new_window(info->mlx, WIN_W, WIN_H, "cub3d null");
	if (info->mlx_win == NULL)
		return (free(info->mlx), 0);
	return (1);
}

int	init_cub(t_cub *info)
{
	info->fd_map = -1;
	info->color_ceilling = -1;
	info->color_floor = -1;
	info->map = malloc(sizeof(t_map));
	if (!info->map)
		return (0);
	info->map->map_height = 0;
	info->map->map_width = 0;
	info->north = ft_calloc(sizeof(t_text), 1);
	info->south = ft_calloc(sizeof(t_text), 1);
	info->east = ft_calloc(sizeof(t_text), 1);
	info->west = ft_calloc(sizeof(t_text), 1);
	if (!info->north | !info->south | !info->west | !info->east)
	{
		free_texture(info);
		free(info->map);
		return (error_message("problem during texture initialisation\n"));
	}
	info->north->img_ptr = NULL;
	info->south->img_ptr = NULL;
	info->east->img_ptr = NULL;
	info->west->img_ptr = NULL;
	if (!init_mlx(info))
		return (error_message("problem during mlx initialisation\n"));
	return (1);
}

int	init_text(t_text *side, void *mlx, char *str)
{
	int		i;
	char	*str_final;

	i = skip_white(str, 0);
	str_final = ft_strdup(str + i);
	if (!str_final)
		return (0);
	str_final[ft_strlen(str_final) - 1] = 0;
	side->img_ptr = mlx_xpm_file_to_image(mlx, str_final, &side->img_width,
			&side->img_height);
	if (!side->img_ptr)
		return (free(str_final), error_message("can't open texture\n"));
	side->addr = mlx_get_data_addr(side->img_ptr, &side->bpx, &side->ln_len,
			&side->endn);
	if (!side->addr)
		return (free(str_final), mlx_destroy_image(mlx, side->img_ptr), 0);
	free(str_final);
	return (1);
}
