# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 11:23:01 by ccestini          #+#    #+#              #
#    Updated: 2022/09/21 10:55:38 by ccestini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= 	main.c map_check_path.c map_check_valid.c map_read.c \
				utils.c utils2.c game.c

OBJS	=	${SRCS:.c=.o}

MLX_DIR		=	./minilibx
MLX_FLAGS	=	-lmlx -lz -framework OpenGL -framework AppKit

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=	-L $(MLX_DIR) -lmlx

%.o : %.c
		$(CC) -Imlx -c -o $@ $<

$(NAME)	:	$(OBJS)
		$(MAKE) -s -C $(MLX_DIR) all
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) $(LFLAGS)

all :	$(NAME)

clean :
		$(RM) $(OBJS) 
		$(MAKE) -s -C $(MLX_DIR) clean

fclean :	clean
		$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re