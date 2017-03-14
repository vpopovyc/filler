/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sm_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:52:15 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/14 17:52:31 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

char    ft_sm_quadrant_4(t_filler *travis)
{
    char c;

    if (travis->l_alp[0] == travis->m_sp[2])
    {
        c = ft_move_left(travis, travis->l_alp[0], travis->l_alp[1]);
        if (c == 0)
        {
            c = ft_move_down(travis, travis->l_alp[0], travis->l_alp[1]);
            if (c == 0)
            {
                c = ft_move_right(travis, travis->l_alp[0], travis->l_alp[1]);
                if (c == 0)
                    c = ft_move_up(travis, travis->l_alp[0], travis->l_alp[1]);
            }
        }
        if (c)
            return (c);
    }
    else
    {
        c = ft_move_up(travis, travis->l_alp[0], travis->l_alp[1]);
        if (c == 0)
        {
            c = ft_move_left(travis, travis->l_alp[0], travis->l_alp[1]);
            if (c == 0)
            {
                c = ft_move_right(travis, travis->l_alp[0], travis->l_alp[1]);
                if (c == 0)
                    c = ft_move_down(travis, travis->l_alp[0], travis->l_alp[1]);
            }
        }
    }
    return (c);
}
