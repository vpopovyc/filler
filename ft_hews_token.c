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

void	ft_realloc_token(t_filler *travis, int fd, short i, short t_i) /* init i = -1 */
{
	char	*tmp;
	char	**new_token;

	ft_fprintf("ft_realloc_token\n", fd);
	tmp = *(travis->token);
	while (*tmp != '\0' && ++i < travis->tok_shapes[0])
		tmp = *(travis->token + i);
	new_token = (char**)malloc(sizeof(char*) * i + 1);
	*(new_token + i) = NULL;
	t_i = i;
	i = -1;
	while (++i != t_i)
	{
		*(new_token + i) = ft_strdup(*(travis->token + i));
		ft_fprintf("%s\n", fd , *(new_token + i));
		free(*(travis->token + i));
	}
	free(travis->token);
	travis->token = new_token;
	travis->tok_shapes[0] = i;
	travis->tok_shapes[1] = ft_strlen(*(travis->token + i - 1));
    ft_fprintf("token = y: %i x: %i n: %i\n", fd, travis->tok_shapes[0], travis->tok_shapes[1], travis->tok_shapes[2]);
}


void	ft_hews(t_filler *travis, int fd, short y, short x, short empty)
{
	ft_fprintf("ft_hews\n", fd);
	travis->tok_shapes[2] = 0;
	while (travis->token[++y])
	{
		x = -1;
		empty = 0;
		while (travis->token[y][++x])
		{
			travis->token[y][x] == '*' ? empty = 0: 0;
			travis->token[y][x] == '*' ? ++travis->tok_shapes[2]: 0;
			if (travis->token[y][x] == '.')
			{
				if (travis->token[y][x + 1] == '\0')
				{
					if (y == 0 && empty + 1 == travis->tok_shapes[1])
						break ;
					travis->token[y][x - empty] = '\0';
				}
				else
					++empty;
			}
		}
	}
	ft_realloc_token(travis, fd, -1, 0);
}
