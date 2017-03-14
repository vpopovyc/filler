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
	int		m_sp[4]; /* [0] = y [1] = x */
	int		t_sp[3];
	char	al_c;
	char	en_c;
	char	**map;
    char    **token;
	short	x_flag;
	short	y_flag;
	char	al_q;
	char	en_q;
	int		fd_place;
	int		fd_map;
	short	l_alp[2];
	short	l_enp[2];
	short	x_max;
}				t_filler;

# define DEL "------------------"
/* ft_init_all.c */
void	ft_get_p_number(t_filler *travis, char *line);
void	ft_get_x_y_of_map(t_filler *travis);
void	ft_get_map(t_filler *travis, short mem_all, short i);
void    ft_get_token(t_filler *travis, short i);
void	ft_get_starting_quad(t_filler *travis, char al, char en, char **map);
/*ft_hews_token.c */
void	ft_hews(t_filler *travis, short y, short x, short empty);
void	ft_realloc_token(t_filler *travis, short i, short t_i);
/* ft_update_map.c */
void	ft_update_all(t_filler *travis);
void	ft_update_map(t_filler *travis, short y, short x, char **map);
void    ft_update_travis_pos_q1l(t_filler *travis, short y, short x, char **map);
void    ft_update_travis_pos_q2(t_filler *travis, short y, short x, char **map);
void    ft_update_travis_pos_q3(t_filler *travis, short y, short x, char **map);
void    ft_update_travis_pos_q4(t_filler *travis, short y, short x, char **map);
/* ft_write_token.c */
char    ft_write_token(t_filler *travis, char **map, short y, short x);
char	ft_check_token(t_filler *travis, char **map, short y, short x);
/* ft_move.c */
int		ft_move_left(t_filler *travis, short y, short x);
int		ft_move_right(t_filler *travis, short y, short x);
int		ft_move_up(t_filler *travis, short y, short x);
int		ft_move_down(t_filler *travis, short y, short x);
/* ft_algo.c */
char    ft_algo(t_filler *travis/*, short y, short x*/);
char    ft_sm_quadrant_4(t_filler *travis);
char    ft_any(t_filler *travis, short y, short x, char **map);
char    ft_algo_small_map(t_filler *travis);
#endif
