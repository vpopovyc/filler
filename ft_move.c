/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:33:19 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/12 02:33:27 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_move_left(t_filler *travis, short y, short x)
{
	short tok_x;
	short i;
	short t_i;
	
	tok_x = 4;
	i = -1;
	x -= travis->t_sp[1] - 1;
	while (++i != tok_x)
	{
		if (ft_check_token(travis, travis->map, y, x + i))
			return (ft_printf("%d %d\n", y, x + i));
		t_i = 0;
		while (++t_i <= travis->t_sp[0])
			if (ft_check_token(travis, travis->map, y - t_i, x + i))
				return (ft_printf("%d %d\n", y - t_i, x + i));
	}
	return (0);
}

int		ft_move_right(t_filler *travis, short y, short x)
{
	short tok_x;
	short i;
	short t_i;

	tok_x = 4;
	i = -1;
	while (++i != tok_x)
	{
		if (ft_check_token(travis, travis->map, y, x - i))
			return (ft_printf("%d %d\n", y, x - i));
		t_i = 0;
		while (++t_i < travis->t_sp[0])
			if (ft_check_token(travis, travis->map, y - t_i, x - i))
				return (ft_printf("%d %d\n", y - t_i, x - i));
	}
	return (0);
}

int		ft_move_up(t_filler *travis, short y, short x)
{
	short tok_y;
	short i;
	short t_i;

	tok_y = travis->t_sp[0];
	i = 0;
	while (++i != tok_y)
	{
		if (ft_check_token(travis, travis->map, y - i, x))
			return (ft_printf("%d %d\n", y - i, x));
		t_i = 0;
		while (++t_i <= travis->t_sp[1])
			if (ft_check_token(travis, travis->map, y - i, x - t_i))
				return (ft_printf("%d %d\n", y - i, x - t_i));
	}
	return (0);
}

int		ft_move_down(t_filler *travis, short y, short x)
{
	short tok_y;
	short i;
	short t_i;
	
	tok_y = travis->t_sp[0];
	i = -1;
	while (++i != tok_y)
	{
		if (ft_check_token(travis, travis->map, y + i, x))
			return (ft_printf("%d %d\n", y + i, x));
		t_i = 0;
		while (++t_i <= travis->t_sp[1])
			if (ft_check_token(travis, travis->map, y + i, x - t_i))
				return (ft_printf("%d %d\n", y + i, x - t_i));
	}
	return (0);
}
