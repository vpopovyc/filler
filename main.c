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

	travis.nfd = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strnstr(line, "$$$", 3))
			ft_get_p_number(&travis, line);
		else if (ft_strnstr(line, "Pl", 2))
			ft_update_all(&travis);
		ft_algo(&travis);
	}
	free(line);
	ft_ppdel(&travis.map);
	ft_ppdel(&travis.token);
	ft_give_birth_to_hedgehog(&travis);
	ft_fprintf("end of game\n", travis.fd);
	close(travis.fd);
	return (1);
}
