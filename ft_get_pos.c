/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:07:01 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/09 21:47:18 by vpopovyc         ###   ########.fr       */
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
	ft_fprintf("ft_try_to_fit\n", fd);
	short	t_x;
	short	x2 = 0;
	short	y2 = 0;
	char	**map;
	char	**tok;
	short	check = 0;
	short	ok = 0;

	ft_fprintf("y: %i, x: %i before flags\n", fd, y, x);
	ft_flag_usage(travis, &x, &y);
	ft_fprintf("y: %i, x: %i after flags\n", fd, y, x);
	t_x = x;
	map = travis->map;
	tok = travis->token;
	while (map[y] && tok[y2] && y >= 0)
	{
		x2 = 0;
		x = t_x;
		ft_fprintf("map_y: %i\ntok_y: %i\nmap_x: %i\n", fd, y, y2, x);
		while (map[y][x] && tok[y2][x2])
		{
			ft_fprintf("map_x: %i - map_char: %c\ntok_x: %i - tok_char: %c\n", fd, x, map[y][x], x2, tok[y2][x2]);
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
	ft_fprintf("check: %i\n", fd, check);
	if (ok == 1 && check == travis->tok_shapes[2] - 1)
		return (1);
	else
		return (0);
}

short	ft_get_pos(t_filler *travis, short y_step, short x_step, int fd)
{
	ft_fprintf("ft_get_pos\n", fd);
	char	**map;
	short 	x;
	short	y;
	short	t_x;
	short 	t_y;

	map = travis->map;
	ft_starting_point(travis, &y, &x, travis->quadrant);
	ft_fprintf("y: %i, x: %i quadrant: %hhd\n", fd, y, x, travis->quadrant);
	ft_step(&y_step, &x_step, travis->quadrant);
	while (map[y] && y >= 0)
	{
		ft_x_point(travis, travis->quadrant, &x);
		while (map[y][x])
		{
			ft_fprintf("y: %i, x: %i quadrant: %hhd\n", fd, y, x, travis->quadrant);
			if (map[y][x] == travis->token_c || map[y][x] == travis->token_c + 32) /* here */
			{
				if (ft_try_to_fit(travis, x, y, fd))
				{
					ft_fprintf("y: %i, x: %i in while\n", fd, y, x);
					t_x = x;
					t_y = y;
					ft_flag_usage(travis, &t_x, &t_y);
					ft_fprintf("y: %i, x: %i output\n", fd, t_y, t_x);
					ft_printf("%d %d\n", t_y, t_x);
					return (1);
				}
				ft_fprintf("Trying to fit again\n\n", fd);
			}
			x += x_step;
		}
		y += y_step;
	}
	ft_putstr_fd("Cant fit\n", fd);
	return (0);
}

short	ft_flags(t_filler *travis, int fd)
{
	ft_fprintf("ft_flags\n", fd);
	travis->x_flag = 0;
	travis->y_flag = 0;
	if (ft_get_pos(travis, 0, 0, fd))
		return (0);
	travis->x_flag = 1;
	if (ft_get_pos(travis, 0, 0, fd))
		return (0);
	travis->x_flag = 0;
	travis->y_flag = 1;
	if (ft_get_pos(travis, 0, 0, fd))
		return (0);
	travis->x_flag = 1;
	if (ft_get_pos(travis, 0, 0, fd))
		return (0);
	ft_fprintf("pizda blya\n", fd);
	return (1);
}
