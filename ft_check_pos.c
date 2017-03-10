/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:27:51 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/10 16:43:56 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_check_midle(t_filler *travis, int fd)
{
	char **map;
	short m_y;
	short m_x;
	short t_x;
	short t_y;

	map = travis->map;
	m_y = travis->map_shapes[0] / 2;
	m_x = -1;
	while (map[m_y][++m_x])
	{
		if (map[m_y][m_x] == travis->token_c || map[m_y][m_x] == travis->token_c + 32)
		{
			if (ft_try_to_fit(travis, m_x, m_y, fd))
			{
				ft_fprintf("y: %i, x: %i in while\n", fd, m_y, m_x);
				t_x = m_x;
				t_y = m_y;
				ft_flag_usage(travis, &t_x, &t_y);
				ft_fprintf("y: %i, x: %i output\n", fd, t_y, t_x);
				ft_printf("%d %d\n", t_y, t_x);
				return (1);
			}
		}
	}
	return (0);
}
