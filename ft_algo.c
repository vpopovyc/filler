/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 22:35:51 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/11 22:36:03 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"


char    ft_algo_small_map(t_filler *travis)
{
    
}

char	ft_algo(t_filler *travis/*, short y, short x*/)
{
    char c;

    c = 0;
    if (travis->m_sp[2] < 10)
         c = ft_algo_small_map(travis);
    return (c);
}
