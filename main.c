/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:09:07 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/11 22:31:48 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		main(void)
{
	t_filler	travis;
	char	*line;

	travis.fd_map = open("log", O_RDWR | O_TRUNC);
	travis.fd_place = open("log_place", O_RDWR | O_TRUNC);
	ft_fprintf("fd_place: %i\n", travis.fd_map, travis.fd_place);
	while (get_next_line(0, &line))
	{
		if (ft_strnstr(line, "$$$", 3))
			ft_get_p_number(&travis, line);
		if (ft_strnstr(line, "Pl", 2))
			ft_update_all(&travis);
		if (!ft_algo(&travis))
			return (ft_printf("-1 -1\n"));
	}
}
