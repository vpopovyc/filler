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

void    ft_get_token(t_filler *travis, short i)
{
	char    *line;

	get_next_line(0, &line);
	travis->t_sp[0] = ft_atoi(line + 6);
	travis->t_sp[1] = ft_atoi(line + 8);
	travis->token = (char**)malloc(sizeof(char*) * travis->t_sp[0] + 1);
	*(travis->token + travis->t_sp[0]) = NULL;
	free(line);
    ft_fprintf("New token\n", travis->fd_map);
	while (++i != travis->t_sp[0])
	{
		get_next_line(0, &line);
		*(travis->token + i) = ft_strsub(line, 0, travis->t_sp[1]);
		free(line);
	}
    ft_hews(travis, -1, -1, 0);
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
}

void	ft_get_x_y_of_map(t_filler *travis)
{
	char    *line;
	
	get_next_line(0, &line);
	travis->m_sp[0] = ft_atoi(line + 7);
	travis->m_sp[1] = ft_atoi(line + 11);
	ft_fprintf("map = y: %i x: %i ", travis->fd_map, travis->m_sp[0], travis->m_sp[1]);
	free(line);
	ft_get_map(travis, 0, -1);
}

void	ft_get_p_number(t_filler *travis, char *line)
{
	travis->al_c = ft_atoi(line + 10) == 1 ? 'O': 'X';
    travis->en_c = travis->al_c == 'X' ? 'O' : 'X';
	ft_fprintf("Player token: %c\n", travis->fd_map, travis->al_c);
    ft_fprintf("Enemy token: %c\n", travis->fd_map, travis->en_c);
	free(line);
	ft_get_x_y_of_map(travis);
}
