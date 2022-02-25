# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iha <iha@student.42.kr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 02:51:56 by iha               #+#    #+#              #
#    Updated: 2022/02/26 02:51:57 by iha              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit -lz
MLX_DIR = -L./mlx_opengl

MLX_OPENGL = mlx_opengl

GET_NEXT_LINE = get_next_line
GET_NEXT_LINE_A = get_next_line/get_next_line.a

LIBFT = libft
LIBFT_A = libft/libft.a

SRCS_DIR = srcs/
SRCS_FILE =	main.c \
			put_img.c \
			set_img.c \
			set_map.c \
			validation.c \
			error.c \
			init.c \
			key.c \
			exit.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILE))

OBJS = $(SRCS:.c=.o)

NAME_SO_LONG = so_long

all: $(LIBFT) $(GET_NEXT_LINE) $(MLX_OPENGL) $(NAME_SO_LONG)

$(LIBFT):
	@make -C $(LIBFT)

$(MLX_OPENGL):
	@make -C $(MLX_OPENGL)

$(GET_NEXT_LINE):
	@make bonus -C $(GET_NEXT_LINE)

$(NAME_SO_LONG): $(LIBFT_A) $(GET_NEXT_LINE_A) $(OBJS)
	$(CC) $(CFLAGS) $(MLX_DIR) $(MLX) $(LIBFT_A) $(GET_NEXT_LINE_A) $(OBJS) -o $(NAME_SO_LONG)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX_OPENGL)
	make clean -C $(GET_NEXT_LINE)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(GET_NEXT_LINE)
	rm -f $(NAME_SO_LONG)

re: fclean all

start:
	./so_long ./map/success_002.ber

.PHONY: all bonus clean fclean re $(LIBFT) $(GET_NEXT_LINE) $(MLX_OPENGL) start
