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

char			ft_write_token(t_filler *travis, char **map, short y, short x)
{
    ft_fprintf("New map would be like\n", travis->fd_place);
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
        {
            if (map[y][x] == travis->al_c || map[y][x] == '.')
                map[y][x] = travis->token[t_y][t_x];
        }
        ft_fprintf("%s\n", travis->fd_place, map[y]);
        ++y;
		++t_y;
	}
    if (travis->al_q == 4)
        ft_update_travis_pos_q4(travis, cp[0], cp[1], map);
    else if (travis->al_q == 3)
        ft_update_travis_pos_q3(travis, cp[0], cp[1], map);
    else if (travis->al_q == 2)
        ft_update_travis_pos_q2(travis, cp[0], cp[1], map);
    else if (travis->al_q == 1)
        ft_update_travis_pos_q1(travis, cp[0], cp[1], map);
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
	while (map[y] && travis->token[t_y[0]] && y >= 0)
	{
		x = tmp_x;
		t_x[0] = 0;
		while (map[y][x] && travis->token[t_y[0]][t_x[0]] && x >= 0)
		{
			ft_fprintf("map: %c token: %c ok: %hhi\n", travis->fd_place, map[y][x], travis->token[t_y[0]][t_x[0]], ok);
			if (travis->token[t_y[0]][t_x[0]] == '*')
            {
				if (!ft_check_write_token(map[y][x], ok, travis->al_c))
					return (0);
                if (map[y][x] == travis->al_c)
                    ok = 1;
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
