# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 15:52:03 by tpan              #+#    #+#              #
#    Updated: 2017/05/14 15:17:14 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -fsanitize=address -g - o push_swap_debug
LEAKCHECK = -g -o push_swap_leakcheck
SRCFILES = 	push_ops.c \
			swap_ops.c \
			rotate_ops.c \
			basic_ops \

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./srcs/
LIBFTDIR = ./libft/
FTPFDIR = ./ft_printf/
INCDIR = ./includes/

.PHONY: $(NAME), all, clean, fclean, re, $(LIBFT)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT)
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "push_swap: Compiled"

$(LIBFT):
	@make -C $(LIBFTDIR) all

$(FT_PRINTF): -o $@
	@make -C $(FTPFDIR) all

clean:
	@echo "Cleaning push_swap"
	@rm -rf $(OBJDIR)
	@rm -rf push_swap_debug
	@rm -rf push_swap_debug.dSYM
	@rm -rf push_swap_leakcheck
	@rm -rf push_swap_leakcheck.dSYM
	@make -C $(LIBFTDIR) clean
	@make -C $(FTPFDIR) clean

fclean: clean
	@echo "FCleaning push_swap"
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(FTPFDIR) fclean

re: fclean all

debug: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling push_swap with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(LEAKCHECK)
