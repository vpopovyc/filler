/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hews_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:42:56 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/09 17:58:20 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_realloc_token(t_filler *travis, short i, short t_i)
{
	char	*tmp;
	char	**new_token;

	ft_fprintf("Token:\n", travis->fd_map);
	tmp = *(travis->token);
	while (*tmp != '\0' && ++i < travis->t_sp[0])
		tmp = *(travis->token + i);
	new_token = (char**)malloc(sizeof(char*) * i + 1);
	*(new_token + i) = NULL;
	t_i = i;
	i = -1;
	while (++i != t_i)
	{
		*(new_token + i) = ft_strdup(*(travis->token + i));
		ft_fprintf("%s\n", travis->fd_map, *(new_token + i));
		free(*(travis->token + i));
	}
	free(travis->token);
	travis->token = new_token;
	travis->t_sp[0] = i;
	travis->t_sp[1] = ft_strlen(*(travis->token + i - 1));
    ft_fprintf("token = y: %i x: %i n: %i\n", travis->fd_map, travis->t_sp[0], travis->t_sp[1], travis->t_sp[2]);
}


void	ft_hews(t_filler *travis, short y, short x, short empty)
{
	travis->t_sp[2] = 0;
	while (travis->token[++y])
	{
		x = -1;
		empty = 0;
		while (travis->token[y][++x])
		{
			travis->token[y][x] == '*' ? empty = 0: 0;
			travis->token[y][x] == '*' ? ++travis->t_sp[2]: 0;
			if (travis->token[y][x] == '.')
			{
				if (travis->token[y][x + 1] == '\0')
				{
					if (y == 0 && empty + 1 == travis->t_sp[1])
						break ;
					travis->token[y][x - empty] = '\0';
				}
				else
					++empty;
			}
		}
	}
	ft_realloc_token(travis, -1, 0);
}
