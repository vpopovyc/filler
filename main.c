/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:09:07 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/17 15:59:52 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		main(void)
{
	t_filler	travis;
	char		*line;

	travis.fd_map = open("log", O_RDWR | O_TRUNC);
	travis.fd_place = open("log_place", O_RDWR | O_TRUNC);
	while (get_next_line(0, &line))
	{
		if (ft_strnstr(line, "$$$", 3))
			ft_get_p_number(&travis, line);
		else if (ft_strnstr(line, "Pl", 2))
			ft_update_all(&travis);
		ft_algo(&travis);
	}
	return (1);
}
