# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 08:52:58 by aamhal            #+#    #+#              #
#    Updated: 2023/03/06 22:27:47 by aamhal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
NAMEB = so_long_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXF = -lmlx -framework OpenGL -framework AppKit
SRC = SRC/main.c SRC/walls.c SRC/characters.c SRC/mlx.c SRC/put_img.c  SRC/wasd.c SRC/moves.c SRC/validpath.c SRC/free.c
PRINTF = libftprintf/libftprintf.a
FT = libftprintf/
BONUS = Bonus/main_bonus.c Bonus/walls_bonus.c Bonus/characters_bonus.c Bonus/check_bonus.c Bonus/mlx_bonus.c Bonus/put_img_bonus.c \
 Bonus/wasd_bonus.c Bonus/moves_bonus.c Bonus/so_long_utils_bonus.c Bonus/validpath_bonus.c Bonus/free_bonus.c
OBJ = $(SRC:.c=.o)
BOBJ= $(BONUS:.c=.o)

all : $(NAME)

%.o : %.c SRC/so_long.h Bonus/so_long_bonus.h libftprintf/ft_printf.h
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME) : $(OBJ)
	@make -s -C $(FT)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(MLXF) -o $(NAME)

bonus : $(BOBJ)
	@make -s -C $(FT)
	$(CC) $(CFLAGS) $(BOBJ) $(PRINTF) $(MLXF) -o $(NAMEB)

clean :
	@rm -rf libftprintf/*.o
	@rm -rf $(OBJ) $(BOBJ)
	
fclean : clean
	@rm -rf libftprintf\*.o $(PRINTF)
	@rm -rf $(NAME) $(NAMEB)

re : fclean all

.PHONY: all fclean clean re 