/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:40:52 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 13:52:14 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	add_map_line(t_link_map **head, t_link_map **current, char *str)
{
	t_link_map	*new_node;

	new_node = malloc(sizeof(t_link_map));
	if (!new_node)
		return (0);
	new_node->value = ft_strdup(str);
	new_node->next = NULL;
	if (!new_node->value)
	{
		free(new_node);
		return (0);
	}
	if (*head == NULL)
	{
		*head = new_node;
		*current = new_node;
	}
	else
	{
		(*current)->next = new_node;
		*current = new_node;
	}
	return (1);
}
