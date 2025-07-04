/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:47:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/04 18:30:36 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}

static size_t	count_words(char const *s, char sep)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		s += ft_charspn(s, sep);
		if (*s)
			count++;
		s += ft_charcspn(s, sep);
	}
	return (count);
}

char	**ft_split(char const *s, char sep)
{
	char	**array;
	size_t	offset;
	int		i;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (count_words(s, sep) + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		s += ft_charspn(s, sep);
		offset = ft_charcspn(s, sep);
		array[i] = ft_strndup(s, offset);
		if (!array[i])
			return (free_split(array, i));
		s += offset;
		i++;
	}
	array[i] = NULL;
	return (array);
}
