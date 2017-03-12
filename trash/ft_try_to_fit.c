/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_to_fit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 01:11:06 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/12 01:11:15 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_try_to_fit(t_filler *travis, short x, short y)
{
	short	t_x;
	short	x2 = 0;
	short	y2 = 0;
	char	**map;
	char	**tok;
	short	check = 0;
	short	ok = 0;
	
	t_x = x;
	map = travis->map;
	tok = travis->token;
	while (map[y] && tok[y2] && y >= 0)
	{
		x2 = 0;
		x = t_x;
		while (map[y][x] && tok[y2][x2])
		{
			if (tok[y2][x2] == '*')
			{
				if (map[y][x] == travis->token_c)
					ok += 1;
				else if (map[y][x] == '.')
					++check;
				else
					return (0);
			}
			++x2;
			++x;
		}
	}
	if (ok == 1 && check == travis->tok_shapes[2] - 1)
		return (1);
	return (0);
}
