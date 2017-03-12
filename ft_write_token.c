/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 01:50:46 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/12 01:50:56 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static char		ft_check_write_token(char map, char ok, char al_c)
{
	if ((map == '.') || (map == al_c && ok == 0))
		return (1);
	return (0);
}


void			ft_get_new_l_pos(t_filler *travis, char **map, short y, short x)
{
	char	flag_x;
	char	flag_y;

	flag_x = travis->al_q == 1 ? 1 : 0;
	flag_y = travis->al_q == 2 ? 1 : 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])

	}
}

char			ft_check_token(t_filler *travis, char **map, short y, short x)
{
	short tmp_x;
	short t_x;
	short t_y;
	short cp[2];

	tmp_x = x;
	t_y = 0;
	cp[0] = y;
	cp[1] = x;
	while (map[y] && travis->token[t_y])
	{
		x = tmp_x - 1;
		t_x = -1;
		while (map[y][++x] && travis->token[t_y][++t_x])
			map[y][x] = travis->token[t_y][t_x];
		++y;
		++t_y;
	}
	ft_get_new_l_pos(travis, map, cp[0] - 1, cp[1] - 1);
	return (1);
}

char			ft_check_token(t_filler *travis, char **map, short y, short x)
{
	ft_fprintf("ft_write_token %y: %i x: %i\n", travis->fd_place, y, x);
	short	t_x[2];
	short	t_y[2];
	short	tmp_x;
	char	ok;

	t_x[1] = x;
	t_y[1] = y;
	tmp_x = x;
	t_y[0] = 0;
	ok = 0;
	while (map[y] && travis->token[t_y[0]])
	{
		x = tmp_x;
		t_x[0] = 0;
		while (map[y][x] && travis->token[t_y[0]][t_x[0]])
		{
			ft_fprintf("map: %c token: %c\n", travis->fd_place, map[y][x], travis->token[t_y[0]][t_x[0]]);
			if (travis->token[t_y[0]][t_x[0]] == '*')
			{
				if (map[y][x] == travis->al_c)
					ok = 1;
				else if (!ft_check_write_token(map[y][x], ok, travis->al_c))
					return (0);
			}
			++x;
			++t_x[0];
		}
		++y;
		++t_y[0];
	}
	ft_fprintf("End of ft_write_token ok: %i\n\n", travis->fd_place, ok);
	if (ok == 1)
		return (ft_write_token(travis, map, t_y[1], t_x[1]));
	return (0);
}
