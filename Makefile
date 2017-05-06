# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 15:52:03 by tpan              #+#    #+#              #
#    Updated: 2017/05/02 18:44:09 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
LIBFT = ./srcs/libft/libft.a
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -fsanitize=address -g - o push_swap_debug
LEAKCHECK = -g -o push_swap_leakcheck
SRCFILES = 	push_swap.c \
			read_input.c \

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./srcs/
LIBFTDIR = ./srcs/libft/
INCDIR = ./includes/

.PHONY: $(NAME), all, clean, fclean, re, $(LIBFT)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT)
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) $(OBJ) $(LIBFT) -o $@
	@echo "push_swap: Compiled"

$(LIBFT):
	@make -C $(LIBFTDIR) all

clean:
	@echo "Cleaning push_swap"
	@rm -rf $(OBJDIR)
	@rm -rf push_swap_debug
	@rm -rf push_swap_debug.dSYM
	@rm -rf push_swap_leakcheck
	@rm -rf push_swap_leakcheck.dSYM
	@make -C $(LIBFTDIR) clean

fclean: clean
	@echo "FCleaning push_swap"
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

debug: $(LIBFT)
	@echo "Compiling push_swap with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck: $(LIBFT)
	@echo "Compiling for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) $(LEAKCHECK)
