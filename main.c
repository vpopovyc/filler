/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:09:07 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/02 21:23:52 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_get_p_number(t_filler *travis, int number, int fd)
{
	travis->token = number == 1 ? 'O': 'X';
	ft_putstr_fd("token: ", fd);
	ft_putendl_fd(&(travis->token), fd);
}

void	ft_get_x_y(t_filler *travis, int x, int y, int fd)
{
	travis->map_shapes[0] = x;
	travis->map_shapes[1] = y;
	ft_putstr_fd("x: ", fd);
	ft_putnbr_fd(travis->map_shapes[0], fd);
	ft_putstr_fd(" y: ", fd);
	ft_putnbr_fd(travis->map_shapes[1], fd);
	ft_putendl_fd("", fd);
}

int		main(void)
{
	char		*line;
	int			fd;
	t_filler	travis;

	get_next_line(0, &line);
	fd = open("out.txt", O_RDWR);
	ft_putendl_fd(line, fd);
	ft_get_p_number(&travis, ft_atoi(line + 10), fd);
	ft_get_s_filler(&travis);
	get_next_line(0, &line);
	ft_putendl_fd(line, fd);
	ft_get_x_y(&travis, ft_atoi(line + 7), ft_atoi(line + 10), fd);
/*	while (1)
	{
		while (get_next_line(0, &line) != 0)
			ft_putendl_fd(line, fd);	
		ft_printf("1 1");
	}
*/}
