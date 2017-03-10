/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:10:15 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/10 16:42:07 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLER_H
# define __FT_FILLER_H

# include "libft/includes/libft.h"
typedef struct	s_filler
{
	int		map_shapes[2]; /* [0] = y [1] = x */
	int		tok_shapes[3];
	char	token_c;
	char	**map;
    char    **token;
	short	x_flag;
	short	y_flag;
	char	quadrant;
}				t_filler;
void		ft_get_s_filler(t_filler *travis, int fd);
void		ft_get_p_number(t_filler *travis, int fd, char *line);
void		ft_get_x_y(t_filler *travis, int fd);
void		ft_get_map(t_filler *travis, int fd);
void        ft_get_token(t_filler *travis, int fd);
/* ft_get_pos.c */ 
int     ft_try_to_fit(t_filler *travis, short x, short y, int fd);
short   ft_flags(t_filler *travis, int fd);
void    ft_flag_usage(t_filler *travis, short *x, short *y);
short   ft_get_pos(t_filler *travis, short y_step, short step_x, int fd);
/* ft_hews_token.c */ 
void    ft_hews(t_filler *travis, int fd, short y, short x, short empty);
void    ft_realloc_token(t_filler *travis, int fd, short i, short t_i);
/* ft_get_updated_map.c */
void	ft_get_updated_map_and_token(t_filler *travis, int fd);
/* ft_quadrant.c */
int     ft_check_midle(t_filler *travis, int fd);
void    ft_get_flag(t_filler *travis, char flag);
char	ft_quadrant(t_filler *travis, char **map, short y, short x);
void    ft_step(short *y, short *x, char quadrant);
void    ft_starting_point(t_filler *travis, short *y, short *x, char quadrant);
void	ft_x_point(t_filler *travis, char quadrant, short *x);
#endif
