/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:07:01 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/07 21:42:04 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
void	ft_flag_usage(t_filler *travis, short *x, short *y)
{
	if (travis->x_flag == 0)
		*x -= travis->tok_shapes[1] - 1;
	if (travis->y_flag == 0)
		*y -= travis->tok_shapes[0] - 1;
}
int		ft_try_to_fit(t_filler *travis, short x, short y, int fd)
{
	short	t_x;
	short	x2 = 0;
	short	y2 = 0;
	char	**map;
	char	**tok;
	short	check = 0;
	short	ok = 0;

	ft_putstr_fd("cord before -> x: ", fd);
	ft_putnbr_fd(x, fd);
	ft_putstr_fd(" y: ", fd);
	ft_putnbr_fd(y, fd);
	ft_flag_usage(travis, &x, &y);
	ft_putstr_fd("cord after  -> x: ", fd);
	ft_putnbr_fd(x, fd);
	ft_putstr_fd(" y: ", fd);
	ft_putnbr_fd(y, fd);
	ft_putstr_fd("\n", fd);
	t_x = x;
	map = travis->map;
	tok = travis->token;
	while (map[y] && tok[y2])
	{
		x2 = 0;
		x = t_x;
		ft_putstr_fd("tok_y: ", fd);
		ft_putnbr_fd(y2, fd);
		ft_putstr_fd("\nmap_y: ", fd);
		ft_putnbr_fd(y, fd);
		ft_putstr_fd("\n", fd);
		while (map[y][x] && tok[y2][x2])
		{
			ft_putstr_fd("tok_x:  ", fd);
			ft_putnbr_fd(x2, fd);
			ft_putstr_fd(" map_x: ", fd);
			ft_putnbr_fd(x, fd);
			ft_putstr_fd("\n", fd);
			ft_putstr_fd("token char: ", fd);
			ft_putchar_fd(tok[y2][x2], fd);
			ft_putstr_fd(" map char: ", fd);
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

short	ft_get_pos(t_filler *travis, int fd)
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
					ft_putstr_fd("x in while: ", fd);
					ft_putnbr_fd(x, fd);
					ft_putstr_fd("\ny in while: ", fd);
					ft_putnbr_fd(y, fd);
					ft_putstr_fd("\n", fd);
					t_x = x;
					t_y = y;
					ft_flag_usage(travis, &t_x, &t_y);
					ft_putstr_fd("t_x in while: ", fd);
					ft_putnbr_fd(t_x, fd);
					ft_putstr_fd("\nt_y in while: ", fd);
					ft_putnbr_fd(t_y, fd);
					ft_putstr_fd("\n", fd);
					ft_printf("%d %d\n", t_y, t_x);
					return (1);
				}
				ft_putstr_fd("Trying to fit again\n\n", fd);
			}
			++x;
		}
		++y;
	}
	ft_putstr_fd("Cant fit\n", fd);
	return (0);
}

void	ft_flags(t_filler *travis, int fd)
{
	travis->x_flag = 0;
	travis->y_flag = 0;
	if (ft_get_pos(travis, fd))
		return ;
	travis->x_flag = 1;
	if (ft_get_pos(travis, fd))
		return ;
	travis->x_flag = 0;
	travis->y_flag = 1;
	if (ft_get_pos(travis, fd))
		return ;
	travis->x_flag = 1;
	if (ft_get_pos(travis, fd))
		return ;
	ft_putstr_fd("pizda blya\n", fd);
}

