/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:07:01 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/11 18:14:40 by vpopovyc         ###   ########.fr       */
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
	ft_fprintf("y: %i, x: %i quadrant: %hhd enemy_quadrant: %hhd\n", fd, y, x, travis->quadrant, travis->enemy_quadrant);
	ft_step(&y_step, &x_step, travis->quadrant);
	if (ft_check_midle(travis, fd))
		return (1);
	while (map[y] && y >= 0)
	{
		:
		{
			ft_fprintf("y: %i, x: %i quadrant: %hhd\n", fd, y, x, travis->quadrant);
			ft_fprintf("x_flag: %i y_flag: %i\n", fd, travis->x_flag, travis->y_flag);
			if ((map[y][x] == travis->token_c || map[y][x] == travis->token_c + 32) && ft_check_opor(map, y, x) == 1)/* here */
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
	if (!ft_flag_midle(travis->map[travis->map_shapes[0] / 2], -1, 0))
		travis->quadrant = travis->enemy_quadrant;
	ft_get_flag(travis, 1);
	if (ft_get_pos(travis, 0, 0, fd))
		return (0);
	travis->x_flag =  travis->x_flag == 1 ? 0 : 1;
	if (ft_get_pos(travis, 0, 0, fd))
		return (0);
	travis->x_flag = travis->x_flag == 1 ? 0 : 1;
	travis->y_flag = travis->y_flag == 1 ? 0 : 1;
	if (ft_get_pos(travis, 0, 0, fd))
		return (0);
	ft_get_flag(travis, 0);
	if (ft_get_pos(travis, 0, 0, fd))
		return (0);
	ft_fprintf("pizda blya\n", fd);
	return (1);
}
