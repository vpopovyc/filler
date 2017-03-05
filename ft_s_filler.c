/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:32:47 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/02 20:38:28 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_get_p_number(t_filler *travis)
{
    char    *line;
    
    get_next_line(0, &line);
    travis->token_c = ft_atoi(line + 10) == 1 ? 'O': 'X';
    free(line);
}

void	ft_get_x_y(t_filler *travis)
{
    char    *line;

    get_next_line(0, &line);
    travis->map_shapes[0] = ft_atoi(line + 7);
    travis->map_shapes[1] = ft_atoi(line + 10);
    free(line);
}

void	ft_get_map(t_filler *travis)
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
        ++i;
        free(line);
    }
}

void    ft_get_token(t_filler *travis)
{
    char    *line;
    char    token_x;
    char    token_y;
    char    i;

    i = 0;
    get_next_line(0, &line);
    token_y = ft_atoi(line + 6);
    token_x = ft_atoi(line + 8);
    travis->token = (char**)malloc(sizeof(char*) * token_y + 1);
    *(travis->token + token_y) = NULL;
    free(line);
    while (i != token_y)
    {
        get_next_line(0, &line);
        *(travis->token + i) = ft_strsub(line, 0, token_x);
        ++i;
        free(line);
    }
}

void	ft_get_s_filler(t_filler *travis)
{
	travis = (t_filler*)malloc(sizeof(t_filler));
    ft_get_p_number(travis);
    ft_get_x_y(travis);
    ft_get_map(travis);
    ft_get_token(travis);
}
