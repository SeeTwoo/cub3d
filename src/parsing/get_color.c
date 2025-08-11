/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 21:08:19 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/08/10 14:23:33 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_color_shift(int *color, int value, int passage)
{
	if (passage == 0)
		*color |= (value << 16);
	else if (passage == 1)
		*color |= (value << 8);
	else
		*color |= value;
}

static int	check_separator(char *str, int *i, int passage)
{
	if (passage < 2)
	{
		*i = skip_white(str, *i);
		if (str[*i] != ',')
			return (error_message("Expected a comma separator\n"));
		(*i)++;
	}
	return (1);
}

static int	parse_one_value(char *str, int *i, int *value)
{
	*i = skip_white(str, *i);
	if (str[*i] < '0' || str[*i] > '9')
		return (error_message("Bad syntax for color\n"));
	*value = ft_atoi(&str[*i]);
	if (*value < 0 || *value > 255)
		return (error_message("Bad value for color, interval is [0, 255]\n"));
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	return (1);
}

static int	convert_rgb_to_int(int *color, char *str)
{
	int	i;
	int	value;
	int	passage;

	i = 0;
	passage = 0;
	*color = 0;
	while (passage < 3)
	{
		if (!parse_one_value(str, &i, &value))
			return (-2);
		apply_color_shift(color, value, passage);
		if (!check_separator(str, &i, passage))
			return (-1);
		passage++;
	}
	i = skip_white(str, i);
	if (str[i] != '\0' && str[i] != '\n')
		return (error_message("Extra characters after RGB color\n"));
	return (1);
}

int	get_color_pars(t_cub *info, char *str)
{
	int	i;
	int	result;

	i = 0;
	result = -1;
	if (info->color_ceilling != -1 && info->color_floor != -1)
		return (2);
	while (str[i] == ' ')
		i++;
	if (str[i] == 'F')
		result = convert_rgb_to_int(&info->color_floor, &str[i + 1]);
	else if (str[i] == 'C')
		result = convert_rgb_to_int(&info->color_ceilling, &str[i + 1]);
	if (result == -1 && str[i] != '\n')
		return (error_message("Missing color\n"));
	if (result == -2 && str[i] != '\n')
		return (0);
	return (result);
}
