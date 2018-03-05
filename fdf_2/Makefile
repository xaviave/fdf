# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/02 14:05:53 by wgaetan      #+#   ##    ##    #+#        #
#    Updated: 2018/03/02 14:05:59 by wgaetan     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

#COMPILATION

NAME = fdf
HEADERS = include/fdf.h
FLAGS = -Wall -Wextra -Werror -g
INC = -I minilibx_macos -I libft
LIBS = minilibx_macos/libmlx.a libft/libft.a libft/libft_matrix/libft_matrix.a
EXT_LIBS = -framework OpenGl -framework AppKit


#PATH

SRCS = srcs/main.c\
	   srcs/parse.c\
	   srcs/get_pt_grid.c\
	   srcs/pt_grid_compute.c\
	   srcs/ft_mtx_display.c\
	   srcs/display.c\
	   srcs/image_manage.c\
	   srcs/bresenham.c\

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
