/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:37:28 by seetwoo           #+#    #+#             */
/*   Updated: 2025/06/24 20:40:11 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE
# define FT_READLINE

typedef struct s_readchar	t_readchar;

struct s_readchar
{
	char		c;
	t_readchar	*next;
}

#endif
