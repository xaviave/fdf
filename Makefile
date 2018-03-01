# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberneli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 07:56:05 by aberneli          #+#    #+#              #
#    Updated: 2018/02/28 22:33:25 by xamartin    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re normy


#COMPILATION

NAME = fdf
HEADERS = include/fdf.h
FLAGS = -Wall -Wextra -Werror
INC = -I minilibx_macos -I libft
LIBS = minilibx_macos/libmlx.a libft/libft.a
EXT_LIBS = -framework OpenGl -framework AppKit


#PATH

SRCS = srcs/main.c\
	   srcs/parse.c\
	   srcs/aff.c\
	   srcs/draw_line.c\

OBJS = $(SRCS:.c=.o)


#RULES

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@$(CC) -ggdb $(FLAGS) $(LIBS) $(EXT_LIBS) $(OBJS) -o $(NAME)

$(LIBS):
	@make -C ./libft
	@make -C ./minilibx_macos

./%.o: ./%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make -C ./libft clean
	@make -C ./minilibx_macos clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@make -C ./minilibx_macos fclean

re: fclean all
	@make -C ./libft re
	@make -C ./minilibx_macos re
