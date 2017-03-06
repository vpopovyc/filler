/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:10:15 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/06 21:13:29 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLER_H
# define __FT_FILLER_H

# include "libft/includes/libft.h"
typedef struct	s_filler
{
	int		map_shapes[2]; /* [0] = y [1] = x */
	int		tok_shapes[2];
	char	token_c;
	char	**map;
    char    **token;
}				t_filler;
void		ft_get_s_filler(t_filler *travis, int fd);
void		ft_get_p_number(t_filler *travis, int fd);
void		ft_get_x_y(t_filler *travis, int fd);
void		ft_get_map(t_filler *travis, int fd);
void        ft_get_token(t_filler *travis, int fd);
/* ft_get_pos.c */ 
int     ft_try_to_fit(t_filler *travis, short x, short y, int fd);
void    ft_get_pos(t_filler *travis, int fd);
/* ft_hews_token.c */ 
void    ft_hews(t_filler *travis/*, int fd*/);
void    ft_realloc_token(t_filler *travis/*, int fd*/, short i, short t_i);
#endif
/* you need to parse map - done!
 * and
 * parse token - done!
 * then write func that could check, if filler can write token in specified x, y
 * algo for srategie */
