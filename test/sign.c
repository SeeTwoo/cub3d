/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:10:58 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/06 08:21:03 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	sign_magic(double n)
{
	return (*(long long *)&n >> 63 & 1);
}

int	main(void)
{
	double	i;

	i = 1.23;
	printf("sign is %d\n", sign_magic(i));
	return (0);
}
