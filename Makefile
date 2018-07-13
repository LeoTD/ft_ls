# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 19:18:37 by ltanenba          #+#    #+#              #
#    Updated: 2018/07/12 21:25:12 by ltanenba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ls 

INCLUDES	= libft/includes/libft.h \
			  includes/ft_ls.h

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I libft/includes -I includes

# Cosmetics Section:

OK_COLOR	= \033[38;5;105;1m
OBJ_COLOR	= \033[38;5;208m
COM_COLOR	= \033[38;5;200m
LIB_COLOR	= \033[1;32m
NO_COLOR    = \033[m

COM_STRING	= "Compiling:"

# End Cosmetics.

LIBFT		= libft/libft.a

LS_SRC		= ft_ls.c \
			  data_handlers.c \
			  flag_handlers.c \
			  print_handlers.c \
			  print_handlers2.c \
			  sort_handlers.c \
			  cmp_functions.c \
			  print_v2.c

SRC			= $(addprefix src/, $(LS_SRC))
OBJ			= $(addprefix obj/, $(LS_SRC:.c=.o))

# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	@printf "%b" "$(LIB_COLOR)Compiling: $(OK_COLOR)$@\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)

$(LIBFT):
	@make -C libft

clean:
	@printf "Cleaning up $(NAME)...\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

obj:
	@printf "Creating obj/ directory...\n"
	@mkdir obj/

obj/%.o: $(SRC) | obj
	@printf "%b" "$(COM_COLOR)  $(COM_STRING) $(OBJ_COLOR)$@\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

norm:
	@printf "%b" "$(LIB_COLOR)Checking Norm...\n$(NO_COLOR)"
	@norminette $(SRC) $(INCLUDES)

test: $(NAME)
	@printf "%b" "$(OK_COLOR)Building...\n$(NO_COLOR)"
	@printf "%b" "$(OK_COLOR)Running...\n$(NO_COLOR)"
	@./$(NAME)

.PHONY: clean fclean all re
