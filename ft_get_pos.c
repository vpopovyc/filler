/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:07:01 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/06 20:22:51 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_try_to_fit(t_filler *travis, short x, short y, int fd)
{
	short	t_x;
	short	x2 = 0;
	short	y2 = 0;
	char	**map;
	char	**tok;
	short	check = 0;
	short	ok = 0;

	ft_putnbr_fd(x, fd);
	ft_putnbr_fd(y, fd);
	ft_putstr_fd("\n", fd);
	x -= travis->tok_shapes[1] - 1;
	y -= travis->tok_shapes[0] - 1;
	ft_putnbr_fd(x, fd);
	ft_putnbr_fd(y, fd);
	ft_putstr_fd("\n", fd);
	t_x = x;
	map = travis->map;
	tok = travis->token;
	ft_putendl_fd(tok[y2], fd);
	while (map[y] && tok[y2])
	{
		x2 = 0;
		x = t_x;
		ft_putstr_fd("y2, y: ", fd);
		ft_putnbr_fd(y2, fd);
		ft_putnbr_fd(y, fd);
		ft_putstr_fd("\n", fd);
		while (map[y][x] && tok[y2][x2])
		{
			ft_putstr_fd("x2, x: ", fd);
			ft_putnbr_fd(x2, fd);
			ft_putnbr_fd(x, fd);
			ft_putstr_fd("\n", fd);
			ft_putstr_fd("token char, map char ", fd);
			ft_putchar_fd(tok[y2][x2], fd);
			ft_putchar_fd(map[y][x], fd);
			ft_putstr_fd("\n", fd);
			if (tok[y2][x2] == '*')
			{
				if (map[y][x] == travis->token_c || map[y][x] == travis->token_c + 32)
					ok += 1;
				else if (map[y][x] == '.')
					++check;
				else
					return (0);
			}
			++x2;
			++x;
		}
		++y2;
		++y;
	}
	ft_putstr_fd("check: " , fd);
	ft_putnbr_fd(check, fd);
	ft_putstr_fd("\n", fd);
	if (ok == 1)
		return (1);
	else
		return (0);
}

void	ft_get_pos(t_filler *travis, int fd)
{
	char	**map;
	short 	x;
	short	y;
	short	t_x;
	short 	t_y;

	map = travis->map;
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == travis->token_c || map[y][x] == travis->token_c + 32)
			{
				if (ft_try_to_fit(travis, x, y, fd))
				{
					ft_putnbr_fd(x, fd);
					ft_putnbr_fd(y, fd);
					ft_putstr_fd(" <-x, y of ter on map\n", fd);
					ft_putendl_fd("return", fd);
					t_x = x;
					t_y = y;
					t_x -= travis->tok_shapes[1] - 1;
					t_y -= travis->tok_shapes[0] - 1;
					ft_putnbr_fd(t_x, fd);
					ft_putnbr_fd(t_y, fd);
					ft_putstr_fd("\n", fd);
					ft_printf("%d %d", t_y, t_x);
					return ;
				}
			}
			++x;
		}
		++y;
	}
	ft_putstr_fd("Cant fit\n", fd);
}
