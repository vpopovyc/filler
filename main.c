/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:09:07 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/07 21:41:31 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		main(void)
{
	int			fd;
	t_filler	travis;
	char	*line;

	fd = open("log", O_RDWR | O_TRUNC);
	while (get_next_line(0, &line))
	{
		if (ft_strnstr(line, "$$$", 3))
			ft_get_p_number(&travis, fd, line);
		if (ft_strnstr(line, "Pl", 2))
			ft_get_updated_map_and_token(&travis, fd);
		ft_flags(&travis, fd);
	}
}
