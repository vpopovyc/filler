/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:32:47 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/11 16:30:40 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void    ft_get_token(t_filler *travis, int fd)
{
    char    *line;
    char    i;

    i = 0;
    get_next_line(0, &line);
    travis->tok_shapes[0] = ft_atoi(line + 6);
    travis->tok_shapes[1] = ft_atoi(line + 8);
    travis->token = (char**)malloc(sizeof(char*) * travis->tok_shapes[0] + 1);
    *(travis->token + travis->tok_shapes[0]) = NULL;
    free(line);
    while (i != travis->tok_shapes[0])
    {
        get_next_line(0, &line);
        *(travis->token + i) = ft_strsub(line, 0, travis->tok_shapes[1]);
		++i;
        free(line);
    }
	ft_hews(travis, fd, -1 , -1, 0);
}

void	ft_get_map(t_filler *travis, int fd)
{
    short	mem_all;
    short	i;
    char	*line;
    
    i = 0;
    mem_all = travis->map_shapes[0];
    travis->map = (char**)malloc(sizeof(char*) * mem_all + 1);
    *(travis->map + mem_all) = NULL;
    get_next_line(0, &line);
    free(line);
    while (i != mem_all)
    {
        get_next_line(0, &line);
        *(travis->map + i) = ft_strsub(line, 4, travis->map_shapes[1]);
		ft_fprintf("%s\n", fd, *(travis->map + i));
        ++i;
        free(line);
    }
    ft_get_token(travis, fd);
}

void	ft_get_x_y(t_filler *travis, int fd)
{
    char    *line;

    get_next_line(0, &line);
    travis->map_shapes[0] = ft_atoi(line + 7);
    travis->map_shapes[1] = ft_atoi(line + 10);
	ft_fprintf("map = y: %i x: %i\n", fd, travis->map_shapes[0], travis->map_shapes[1]);
    free(line);
	ft_get_map(travis, fd);
	travis->quadrant = ft_quadrant(travis, travis->map, -1, -1);
	travis->enemy_quadrant = ft_enemy_quadrant(travis, travis->map, -1, -1);
}

void	ft_get_p_number(t_filler *travis, int fd, char *line)
{
	travis->token_c = ft_atoi(line + 10) == 1 ? 'O': 'X';
	ft_fprintf("Player token: %c\n", fd_map, &travis->token_c);
	free(line);
	ft_get_x_y(travis, fd);
}
