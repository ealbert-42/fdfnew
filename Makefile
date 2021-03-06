# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/20 15:54:21 by ealbert           #+#    #+#              #
#    Updated: 2016/10/20 17:24:00 by ealbert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re all clean fclean

SRC = src/fdf.c		\
	  src/save.c	\
	  src/parser.c	\

NAME = fdf

INCLUDES = -I includes -framework OpenGl -framework AppKit -lmlx

FLAGS = -Wall -Wextra -Werror

$(NAME) :
	make re -C libft/
	make re -C minilibx_macos/
	gcc $(FLAGS) -o $(NAME) $(INCLUDES) $(SRC) minilibx_macos/libmlx.a \
	libft/libft.a

all : $(NAME)

clean :
	make clean -C minilibx_macos/
	make fclean -C libft/

fclean : clean
	rm -f $(NAME)

re : fclean all
