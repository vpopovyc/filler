/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:10:15 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/02 20:32:31 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLER_H
# define __FT_FILLER_H

# include "libft/includes/libft.h"
typedef struct	s_filler
{
	int		map_shapes[2]; /* [0] = y [1] = x */
	char	token_c;
	char	**map;
    char    **token;
}				t_filler;
void		ft_get_s_filler(t_filler *travis);
void		ft_get_p_number(t_filler *travis);
void		ft_get_x_y(t_filler *travis);
void		ft_get_map(t_filler *travis);
void        ft_get_token(t_filler *travis);
#endif
/* you need to parse map - done!
 * and
 * parse token - done!
 * then write func that could check, if filler can write token in specified x, y
 * algo for srategie */
