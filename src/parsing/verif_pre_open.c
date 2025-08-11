/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_pre_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:03:16 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/26 10:25:47 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	nb_arg(int nb)
{
	if (nb < 2)
		return (error_message("cub3d need a map\n"));
	if (nb > 3)
		return (error_message("too many arguments"));
	return (1);
}

int	end_with_cub(char *argv)
{
	int	i;

	i = 0;
	if (ft_strlen(argv) < 4)
		return (error_message("wrong extension: need .cub\n"));
	while (argv[i])
		i++;
	if ((*(int *)&argv[i - 4]) == (*(int *)".cub"))
		return (1);
	return (error_message("wrong extension: need .cub\n"));
}

int	verif_pre_open(int argc, char **argv)
{
	if (!nb_arg(argc))
		return (0);
	if (!end_with_cub(argv[1]))
		return (0);
	return (1);
}
