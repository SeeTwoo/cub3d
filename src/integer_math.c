/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:07:18 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/09 02:37:51 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	int_pow(int n, int pow)
{
	int	i;
	int	result;

	if (pow == 0)
		return (1);
	i = 1;
	result = n;
	while (i < pow)
	{
		result *= n;
		i++;
	}
	return (result);
}
