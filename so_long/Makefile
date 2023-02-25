# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 08:52:58 by aamhal            #+#    #+#              #
#    Updated: 2023/02/24 21:06:46 by aamhal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXF = -lmlx -framework OpenGL -framework AppKit
SRC = SRC/main.c SRC/walls.c SRC/characters.c SRC/mlx.c SRC/put_img.c  SRC/wasd.c SRC/moves.c SRC/so_long_utils.c SRC/validpath.c
PRINTF = libftprintf/libftprintf.a
FT = libftprintf/
BONUS = Bonus/main_bonus.c Bonus/walls_bonus.c Bonus/characters_bonus.c Bonus/mlx_bonus.c Bonus/put_img_bonus.c  Bonus/wasd_bonus.c Bonus/moves_bonus.c Bonus/so_long_utils_bonus.c
OBJ = $(SRC:.c=.o)
BOBJ= $(BONUS:.c=.o)

all : $(NAME)
	@make -s -C $(FT)

$(NAME) : $(OBJ)  SRC/so_long.h
	@make -C $(FT)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(MLXF) -o $(NAME)

bonus : $(BOBJ)  Bonus/so_long_bonus.h 
	@make -C $(FT)
	@$(CC) $(CFLAGS) $(BOBJ) $(PRINTF) $(MLXF) -o $(NAME)
	
%.o : %.c so_long.h so_long_bonus.h
	$(CC) $(CFLAGS) -c $<

clean :
	@rm -rf libftprintf/*.o
	@rm -rf $(OBJ) $(BOBJ)
	
fclean : clean
	@rm -rf libftprintf\*.o $(PRINTF)
	@rm -rf $(NAME)

re : fclean all

.PHONY: all fclean clean re 