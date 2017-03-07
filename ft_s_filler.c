/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:32:47 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/07 20:43:13 by vpopovyc         ###   ########.fr       */
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
	ft_putnbr_fd(travis->tok_shapes[0], fd);
	ft_putnbr_fd(travis->tok_shapes[1], fd);
	ft_putstr_fd("\n", fd);
    travis->token = (char**)malloc(sizeof(char*) * travis->tok_shapes[0] + 1);
    *(travis->token + travis->tok_shapes[0]) = NULL;
    free(line);
    while (i != travis->tok_shapes[0])
    {
        get_next_line(0, &line);
        *(travis->token + i) = ft_strsub(line, 0, travis->tok_shapes[1]);
        ft_putendl_fd(*(travis->token + i), fd);
		++i;
        free(line);
    }
	ft_hews(travis, fd);
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
		ft_putendl_fd(*(travis->map + i), fd);
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
	ft_putnbr_fd(travis->map_shapes[0], fd);
	ft_putnbr_fd(travis->map_shapes[1], fd);
	ft_putstr_fd("\n", fd);
    free(line);
	ft_get_map(travis, fd);
}

void	ft_get_p_number(t_filler *travis, int fd, char *line)
{
	travis->token_c = ft_atoi(line + 10) == 1 ? 'O': 'X';
	ft_putendl_fd(&travis->token_c, fd);
	free(line);
	ft_get_x_y(travis, fd);
}
