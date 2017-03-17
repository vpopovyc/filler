/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 22:35:51 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/17 15:28:08 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

short	ft_sq_man_dist(short x0, short y0, short x1, short y1)
{
	short	res;

	x0 = x1 - x0;
	y0 = y1 - y0;
	res = (x0 * x0) + (y0 * y0);
	return (res);
}

char	ft_find_enemy(t_filler *travis, char **map)
{
	short	x;
	short	y;

	y = -1;
	while (map[++y] && (x = -1) == -1)
	{
		while (map[y][++x])
		{
			if (map[y][x] == travis->en_c)
			{
				if (ft_check_space_around(travis, map, y, x))
				{
					travis->ev[0] = y;
					travis->ev[1] = x;
					return (42);
				}
			}
		}
	}
	return (0);
}

char	ft_is_in_field(t_filler *travis, short y, short x)
{
	if (travis->m_sp[0] - y - travis->t_sp[0] < 0)
		return (0);
	else if (travis->m_sp[1] - x - travis->t_sp[1] < 0)
		return (0);
	return (1);
}

void	ft_pretty_random_leap(t_filler *travis, char **map, short vy, short vx)
{
	short	x;
	short	y;
	short	tmp1;
	short	tmp2;

	y = -1;
	while (map[++y] && (x = -1) == -1)
	{
		while (map[y][++x])
		{
			if (ft_is_in_field(travis, y, x) && ft_check_tok(travis, map, y, x))
				if (ft_find_enemy(travis, map) || (vy == -1 && vx == -1))
				{
					tmp1 = ft_sq_man_dist(vx, vy, travis->ev[1], travis->ev[0]);
					tmp2 = ft_sq_man_dist(x, y, travis->ev[1], travis->ev[0]);
					if ((tmp1 > tmp2) || (vy == -1 && vx == -1))
					{
						vy = y;
						vx = x;
					}
				}
		}
	}
	ft_printf("%hi %hi\n", vy, vx);
}

void	ft_algo(t_filler *travis)
{
	travis->ev[0] = 0;
	travis->ev[1] = 0;
	ft_pretty_random_leap(travis, travis->map, -1, -1);
}
