# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 08:52:58 by aamhal            #+#    #+#              #
#    Updated: 2023/02/21 15:50:02 by aamhal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXF = -lmlx -framework OpenGL -framework AppKit
HEADER = so_long.h
SRC = main.c walls.c characters.c mlx.c put_img.c  wasd.c moves.c \
	 get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OFILES := $(CFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) 
	$(CC) $(CFLAGS) $(SRC) $(MLXF) -o $(NAME)

clean :
	@rm -rf $(OBJ)
	
fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all fclean clean re 