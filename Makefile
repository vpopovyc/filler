# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 15:12:00 by vpopovyc          #+#    #+#              #
#    Updated: 2017/03/19 19:10:08 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/travis.filler

SRC = main.c ft_init_all.c ft_update_map.c ft_check_token.c ft_algo.c ft_hews_token.c

INC = -I ft_filler.h

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

CFLAGS = -c -Wall -Werror -Wextra

MLXCFLAGS = -I /usr/X11/include -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit

LIBINC = -L./libft -lft

all: $(NAME)

obj: $(OBJ)

$(NAME) : liball obj
	clang -o $(NAME) $(LIBINC) $(MLXCFLAGS) $(OBJ)

%.o: %.c
	clang $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

liball:
	@make -C libft/ all

libclean:
	@make -C libft/ clean

libfclean:
	@make -C libft/ fclean

libre: libfclean liball
