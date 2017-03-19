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

void	ft_give_birth_to_hedgehog(t_filler *travis)
{
	char	*name;
	char	*tmp;
	
	tmp = ft_sstoab(travis->nfd, 10);
	name = ft_strjoin("logs/", tmp);
	travis->fd = open(name, O_TRUNC | O_CREAT | O_RDWR, 00777);
    free(name);
    free(tmp);
}

void	ft_update_map(t_filler *travis, short y, short x, char **map)
{
	char	*line;
	short	x_u;

	get_next_line(0, &line);
	free(line);
	ft_give_birth_to_hedgehog(travis);
	while (map[++y])
	{
		get_next_line(0, &line);
		x_u = 3;
		while (map[y][++x] && line[++x_u])
		{
			if (map[y][x] != line[x_u])
				map[y][x] = line[x_u];
		}
		ft_fprintf("%s\n", travis->fd, map[y]);
		free(line);
		x = -1;
	}
	close(travis->fd);
}

void	ft_update_all(t_filler *travis)
{
	++travis->nfd;
	ft_update_map(travis, -1, -1, travis->map);
	ft_ppdel(&travis->token);
	ft_get_token(travis, -1);
}
