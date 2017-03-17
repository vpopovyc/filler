/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:27:33 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/17 15:58:31 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_update_map(/*t_filler *travis,*/ short y, short x, char **map)
{
	char	*line;
	short	x_u;

	get_next_line(0, &line);
	free(line);
	while (map[++y])
	{
		get_next_line(0, &line);
		x_u = 3;
		while (map[y][++x] && line[++x_u])
		{
			if (map[y][x] != line[x_u])
				map[y][x] = line[x_u];
		}
		free(line);
		x = -1;
	}
}

void	ft_update_all(t_filler *travis)
{
	ft_update_map(/*travis, */-1, -1, travis->map);
	ft_ppdel(&travis->token);
	ft_get_token(travis, -1);
}
