/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:10:15 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/11 16:52:10 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLER_H
# define __FT_FILLER_H

# include "libft/includes/libft.h"
typedef struct	s_filler
{
	int		m_sp[2];
	int		t_sp[3];
	char	al_c;
    char    en_c;
	char	**map;
    char    **token;
	int		fd_place;
	int		fd_map;
    short   ev[2];
}				t_filler;

# define DEL "------------------"
/* ft_hews.c */
void	ft_hews(t_filler *travis, short y, short x, short empty);
void	ft_realloc_token(t_filler *travis, short i, short t_i);
/* ft_init_all.c */
void	ft_get_p_number(t_filler *travis, char *line);
void	ft_get_x_y_of_map(t_filler *travis);
void	ft_get_map(t_filler *travis, short mem_all, short i);
void    ft_get_token(t_filler *travis, short i);
/* ft_update_map.c */
void	ft_update_all(t_filler *travis);
void	ft_update_map(t_filler *travis, short y, short x, char **map);
/* ft_write_token.c */
char    ft_check_space_around(t_filler *travis, char **map, short y, short x);
char	ft_check_tok(t_filler *travis, char **map, short y, short x);
/* ft_algo.c */
void    ft_algo(t_filler *travis);
void    ft_pretty_random_leap(t_filler *travis, char **map, short vy, short vx);
#endif
