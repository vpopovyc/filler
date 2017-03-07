# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 15:12:00 by vpopovyc          #+#    #+#              #
#    Updated: 2017/03/07 19:00:58 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/travis.filler

SRC = main.c ft_s_filler.c ft_get_pos.c ft_hews_token.c ft_get_updated_map.c

INC = -I ft_filler.h

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

CFLAGS = -c -Wall -Werror -Wextra

LIBINC = -L./libft -lft

all: $(NAME)

obj: $(OBJ)

$(NAME) : liball obj
	gcc -o $(NAME) $(LIBINC) $(OBJ)

%.o: %.c
	gcc $(CFLAGS) -o $@ $<

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
