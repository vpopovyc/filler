/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_updated_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:39:07 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/07 20:43:54 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_get_updated_map_and_token(t_filler *travis, int fd)
{
	ft_ppdel(&travis->map);
	ft_ppdel(&travis->token);
	ft_get_map(travis, fd);
}
