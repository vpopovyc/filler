/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:25:22 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/11 18:25:36 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_get_starting_quad(t_filler *travis, char al, char en, char **map)
{
	short	x;
	short	y;
	char	quad;

	x = -1;
	y = -1;
	quad = 1;
	while (map[++y])
	{
		while (map[y][++x])
		{
			if (x > travis->m_sp[3] && (quad != 2 || quad != 4))
				quad = (quad == 1) ? 2 : 4;
			if (map[y][x] == al)
			{
				travis->al_q = quad;
				travis->l_alp[0] = y;
				travis->l_alp[1] = x;
			}
			else if (map[y][x] == en)
			{
				travis->en_q = quad;
				travis->l_enp[0] = y;
				travis->l_enp[1] = x;
			}
		}
		x = -1;
		quad = (y < travis->m_sp[2]) ? 1 : 3;
	}
	ft_fprintf("quadrant: travis: %i enemy: %i\n", travis->fd_map, travis->al_q, travis->en_q);
	ft_fprintf("last pos: travis: x: %i y: %i _ enemy: x: %i y: %i\n", travis->fd_map, travis->l_alp[0], travis->l_alp[1], travis->l_enp[0], travis->l_enp[1]);
}

void    ft_get_token(t_filler *travis, short i)
{
	char    *line;

	get_next_line(0, &line);
	travis->t_sp[0] = ft_atoi(line + 6);
	travis->t_sp[1] = ft_atoi(line + 8);
	travis->token = (char**)malloc(sizeof(char*) * travis->t_sp[0] + 1);
	*(travis->token + travis->t_sp[0]) = NULL;
	free(line);
	while (++i != travis->t_sp[0])
	{
		get_next_line(0, &line);
		*(travis->token + i) = ft_strsub(line, 0, travis->t_sp[1]);
		free(line);
	}
	ft_hews(travis, -1 , -1, 0);
}

void	ft_get_map(t_filler *travis, short mem_all, short i)
{
	char	*line;
	
	mem_all = travis->m_sp[0];
	travis->map = (char**)malloc(sizeof(char*) * mem_all + 1);
	*(travis->map + mem_all) = NULL;
	get_next_line(0, &line);
	free(line);
	ft_fprintf("Map:\n", travis->fd_map);
	while (++i != mem_all)
	{
		get_next_line(0, &line);
		*(travis->map + i) = ft_strsub(line, 4, travis->m_sp[1]);
		ft_fprintf("%s\n", travis->fd_map, *(travis->map + i));
		free(line);
	}
	ft_get_token(travis, -1);
	ft_get_starting_quad(travis, travis->al_c, travis->en_c, travis->map);
}

void	ft_get_x_y_of_map(t_filler *travis)
{
	char    *line;
	
	get_next_line(0, &line);
	travis->m_sp[0] = ft_atoi(line + 7);
	travis->m_sp[1] = ft_atoi(line + 11);
	travis->m_sp[2] = travis->m_sp[0] / 2;
	travis->m_sp[3] = travis->m_sp[1] / 2;
	ft_fprintf("map = y: %i x: %i ", travis->fd_map, travis->m_sp[0], travis->m_sp[1]);
	ft_fprintf("m_y: %i m_x %i\n", travis->fd_map, travis->m_sp[2], travis->m_sp[3]);
	free(line);
	ft_get_map(travis, 0, -1);
}

void	ft_get_p_number(t_filler *travis, char *line)
{
	travis->al_c = ft_atoi(line + 10) == 1 ? 'O': 'X';
	travis->en_c = (travis->al_c == 'O') ? 'X' : 'O';
	ft_fprintf("Player token: %c\n", travis->fd_map, travis->al_c);
	ft_fprintf("Enemy token: %c\n", travis->fd_map, travis->en_c);
	free(line);
	ft_get_x_y_of_map(travis);
}
