/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:43:26 by seb               #+#    #+#             */
/*   Updated: 2025/07/30 14:04:14 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	line_is_map_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1')
		{
			i++;
			continue ;
		}
		if (str[i] == ' ' || str[i] == '\n')
		{
			i++;
			continue ;
		}
		if (str[i] == 'W' || str[i] == 'N' || str[i] == 'E' || str[i] == 'S')
		{
			i++;
			continue ;
		}
		return (0);
	}
	return (1);
}

static int	transfer_list_to_map(t_map *map, t_link_map *head)
{
	t_link_map	*current;
	int			i;

	map->map = ft_calloc(sizeof(char *), map->map_height + 1);
	if (!map->map)
		return (0);
	current = head;
	i = 0;
	while (current)
	{
		map->map[i] = ft_calloc(sizeof(char), map->map_width + 2);
		if (!map->map[i])
		{
			free_tab(map->map);
			return (0);
		}
		ft_memcpy(map->map[i], current->value, ft_strlen(current->value));
		current = current->next;
		i++;
	}
	return (1);
}

static int	read_map_to_list(t_cub *info, t_map *map, t_link_map **head)
{
	t_link_map	*current;

	current = NULL;
	while (line_is_map_valid(info->str))
	{
		if (!add_map_line(head, &current, info->str))
		{
			free(info->str);
			free_node(*head);
			return (0);
		}
		if (ft_strlen(info->str) > map->map_width)
			map->map_width = ft_strlen(info->str);
		free(info->str);
		info->str = get_next_line(info->fd_map);
		map->map_height++;
	}
	return (1);
}

int	parse_map(t_cub *info, t_map *map)
{
	t_link_map	*head;

	head = NULL;
	map->map_height = 0;
	map->map_width = 0;
	(void)map;
	info->str = skip_empty_line(info);
	if (!info->str)
		return (0);
	if (!read_map_to_list(info, map, &head))
		return (0);
	if (!transfer_list_to_map(map, head))
	{
		free(info->str);
		free_node(head);
		return (0);
	}
	free(info->str);
	free_node(head);
	return (1);
}
