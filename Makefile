# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 16:01:30 by tpan              #+#    #+#              #
#    Updated: 2017/05/27 16:01:33 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -fsanitize=address -g
LEAKCHECK = -g
SRCFILES = 	alt_sort.c \
			calculate_moves.c \
			debug_feature.c \
			find_optimal_path.c \
			init_ops.c \
			parse_args.c \
			print_output.c \
			push_ops.c \
			read_input.c \
			rev_rotate_ops.c \
			rot_largest_to_top.c \
			rot_smallest_to_top.c \
			sort_stacks.c \
			utility.c\
			swap_ops.c \
			rotate_ops.c \
			basic_ops.c \

CMAINSRC = checker_main.c
PSMAINSRC = pswap_main.c
SRC = $(addprefix $(SRCDIR),$(SRCFILES))
OBJ = $(addprefix $(OBJDIR),$(SRCFILES:.c=.o))

CMAIN = $(addprefix $(SRCDIR),$(CMAINSRC))
COBJ = $(addprefix $(OBJDIR),$(CMAINSRC:.c=.o))

PSMAIN = $(addprefix $(SRCDIR),$(PSMAINSRC))
PSOBJ = $(addprefix $(OBJDIR),$(PSMAINSRC:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./srcs/
LIBFTDIR = ./libft/
FTPFDIR = ./ft_printf/
INCDIR = ./includes/

.PHONY: $(NAME), $(LIBFT), all, clean, fclean, re

all: $(LIBFT) $(FT_PRINTF) checker $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) checker
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC) $(PSMAIN)
	@mkdir -p $(OBJDIR)
	@mv $(SRCFILES:.c=.o) $(PSMAINSRC:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) $(OBJ) $(LIBFT) $(PSOBJ) $(FT_PRINTF) -o $@
	@echo "push_swap: Compiled"

checker: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling pswap checker"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC) $(CMAIN)
	@mkdir -p $(OBJDIR)
	@mv $(SRCFILES:.c=.o) $(CMAINSRC:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) $(OBJ) $(COBJ) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "checker: Compiled"

$(LIBFT):
	@make -C $(LIBFTDIR) all

$(FT_PRINTF): $(LIBFT)
	@make -C $(FTPFDIR) all

clean:
	@echo "Cleaning push_swap"
	@rm -rf $(OBJDIR)
	@rm -rf push_swap_debug
	@rm -rf push_swap_debug.dSYM
	@rm -rf push_swap_leakcheck
	@rm -rf push_swap_leakcheck.dSYM
	@rm -rf checker_debug
	@rm -rf checker_debug.dSYM
	@rm -rf checker_leakcheck
	@rm -rf checker_leakcheck.dSYM
	@make -C $(LIBFTDIR) clean
	@make -C $(FTPFDIR) clean

fclean: clean
	@echo "FCleaning push_swap"
	@rm -rf $(NAME) checker
	@make -C $(LIBFTDIR) fclean
	@make -C $(FTPFDIR) fclean

re: fclean all

debug: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling push_swap with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(PSMAIN) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(DEBUGFLAGS) -o push_swap_debug
	$(CC) $(CFLAGS) $(SRC) $(CMAIN) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(DEBUGFLAGS) -o checker_debug

leakcheck: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(PSMAIN) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(LEAKCHECK) -o push_swap_leakcheck
	$(CC) $(CFLAGS) $(SRC) $(CMAIN) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(LEAKCHECK) -o checker_leakcheck
