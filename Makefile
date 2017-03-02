# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 15:12:00 by vpopovyc          #+#    #+#              #
#    Updated: 2017/03/02 20:58:49 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/travis.filler

SRC = main.c ft_s_filler.c

INC = -I ft_filler.h

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

CFLAGS = -c -Wall -Werror -Wextra

LIBINC = -L./libft -lft

all: $(NAME)

libc:
	make -C libft	

obj: $(OBJ)

$(NAME) : libc obj
	gcc -o $(NAME) $(LIBINC) $(OBJ)

%.o: %.c
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
