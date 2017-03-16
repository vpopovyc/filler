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

char    ft_check_space_around(t_filler *travis, char **map, short y, short x)
{
    char    ok;
    
    ok = 0;
    if ((y + 2 < travis->m_sp[0])
        && map[y][x] == '.' && map[y + 1][x] == '.' && map[y + 2][x] == '.')
        ++ok;
    if ((y - 2 > -1)
        && map[y - 1][x] == '.' && map[y - 2][x] == '.')
        ++ok;
    if ((x + 2 < travis->m_sp[1])
        && map[y][x] == '.' && map[y][x + 1] == '.' && map[y][x + 2] == '.')
        ++ok;
    if ((x - 2 > -1)
        && map[y][x - 1] == '.' && map[y][x - 2] == '.')
        ++ok;
    if (ok > 1)
        return (42);
    return (0);
}

char			ft_check_tok(t_filler *travis, char **map, short y, short x)
{
    char	ok;
    short   tx;
    short   ty;
    short   xt;

    xt = x - 1;
    ty = -1;
    ok = 0;
    while (map[y] && travis->token[++ty] && (tx = -1) == -1 && (x = xt) == xt)
    {
        while (map[y][++x] && travis->token[ty][++tx])
        {
            if (travis->token[ty][tx] == '*')
            {
                if (!ft_check_write_token(map[y][x], ok, travis->al_c))
                    return (0);
                if (map[y][x] == travis->al_c)
                    ok = 1;
            }
        }
        ++y;
    }
    return (ok);
}
