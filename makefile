# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 17:33:24 by momil-vo          #+#    #+#              #
#    Updated: 2024/06/06 21:34:23 by momil-vo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c aux_functions.c key_controls.c mouse_controls.c drawing.c \
		 color.c color2.c complex.c

LIBFT = libft/libft.a

OFLAGS = -O3

LFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm -lbsd

CFLAGS = -Wall -Werror -Wextra

SFLAGS = -g3 -fsanitize=address

FLAGS = $(CFLAGS) $(LFLAGS)

MACFLAGS = $(CFLAGS) -Iinclude -lmlx -lm -framework OpenGL -framework AppKit \
			-I/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers

CC = gcc

all: $(NAME)

$(LIBFT):
	@make --directory libft all clean
	@echo "\033[0;32m$(LIBFT) created\033[0m"

$(NAME): $(LIBFT)
	$(CC) $(SRCS) $(LIBFT) $(FLAGS) $(OFLAGS) -o $(NAME)
	@echo "\033[0;32m$(NAME) created\033[0m"

sanitize: $(LIBFT)
	@rm -f sanitize.out
	$(CC) $(SRCS) $(LIBFT) $(FLAGS) $(SFLAGS) -o sanitize.out
	@echo "\033[0;32msanitize.out created\033[0m"

debug: $(LIBFT)
	@rm -f debug.out
	$(CC) $(SRCS) $(LIBFT) $(FLAGS) -g -o debug.out
	@echo "\033[0;32mdebug.out created\033[0m"

mac: $(LIBFT)
	@$(CC) $(MACFLAGS) $(LIBFT) $(SRCS) -o $(NAME)
	@echo "\033[0;32m$(NAME) created\033[0m"

sanitize_mac: $(LIBFT)
	@rm -f sanitize.out
	@$(CC) $(LIBFT) $(SRCS) $(MACFLAGS) $(SFLAGS) -o sanitize.out
	@echo "\033[0;32msanitize.out created\033[0m"

debug_mac: $(LIBFT)
	@rm -f debug.out
	@$(CC) $(MACFLAGS) -g $(LIBFT) $(SRCS) -o debug.out
	@echo "\033[0;32mdebug.out created\033[0m"

norm:
	norminette $(SRCS) fractol.h

clean:
	@rm -f $(LIBFT)
	@echo "\033[0;31m.a files deleted\033[0m"
	@rm -f $(NAME)
	@echo "\033[0;31mfractol deleted\033[0m"
	@rm -f -r $(NAME).dSYM
	@rm -f debug.out
	@rm -f -r debug.out.dSYM
	@rm -f sanitize.out
	@rm -f -r sanitize.out.dSYM
	@echo "\033[0;31m.out files and related folders deleted\033[0m"

fclean: clean

re: fclean all

.PHONY: all clean fclean re debug mac debug_mac
