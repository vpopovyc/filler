/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadrant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:05:11 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/09 21:39:10 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_x_point(t_filler *travis, char quadrant, short *x)
{
	if (quadrant == 4 || quadrant == 2)
		*x = 0;
	else
		*x = travis->map_shapes[1] - 1;
}

void	ft_starting_point(t_filler *travis, short *y, short *x, char quadrant)
{
	if (quadrant == 4)
	{
		*y = 0;
		*x = 0;
	}
	else if (quadrant == 3)
	{
		*y = 0;
		*x = travis->map_shapes[1] - 1;
	}
	else if (quadrant == 2)
	{
		*y = travis->map_shapes[0] - 1;
		*x = 0;
	}
	else if (quadrant == 1)
	{
		*y = travis->map_shapes[0] - 1;
		*x = travis->map_shapes[1] - 1;
	}
}

void	ft_step(short *y, short *x, char quadrant)
{
	if (quadrant == 4)
	{
		*y = 1;
		*x = 1;
	}
	else if (quadrant == 3)
	{
		*y = 1;
		*x = -1;
	}
	else if (quadrant == 2)
	{
		*y = -1;
		*x = 1;
	}
	else if (quadrant == 1)
	{
		*y = -1;
		*x = -1;
	}
}

char	ft_quadrant(t_filler *travis, char **map, short y, short x)
{
	char c;

	c = travis->token_c;
	while (map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (map[y][x] == c)
			{
				if (y < travis->map_shapes[0] / 2)
				{
					if (x < travis->map_shapes[1] / 2)
						return (1);
					return (2);
				}
				else
				{
					if (x < travis->map_shapes[1] / 2)
						return (3);
					return (4);
				}
			}
		}
	}
	return (-1);
}
