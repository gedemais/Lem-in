# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 11:15:08 by gedemais          #+#    #+#              #
#    Updated: 2019/03/27 12:30:54 by qudesvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), $(OBJS), clean, fclean, re
	
DEF = \033[0m
GRA = \033[1m
SOU = \033[4m
BLI = \033[5m
BLA = \033[30m
RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
PUR = \033[35m
CYA = \033[36m
WHI = \033[37m
ORG = \033[1;31m

CC = gcc

FLAGS = -Wall -Werror -Wextra

INC = includes/map_creator.h

SRCS_NAME = ft_draw.c \
			map_creator.c \
			main.c \
			ft_env.c \
			ft_fill.c \
			built.c \
			export.c \
			display_term.c \
			ft_usage.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = $(SRCS_NAME:.c=.o)

LIB = libft/libft.a

NAME = map_creator

all: $(NAME) $(INC)

$(NAME): $(LIB) $(SRCS)
	@echo "Making $(RED)$(NAME)...$(DEF)"
	$(CC) $(FLAGS) -o $(NAME) -I /usr/local/include/ -I includes/ -I libft/ $(SRCS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB)
	@echo "$(GRE)Done !$(DEF)"

$(LIB): FORCE
	@make -C libft/

clean:
	@rm -rf $(OBJS)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJS)
	@make -C libft/ fclean
	@echo "$(YEL)libft.a$(DEF) deleted."

FORCE:

re: fclean all
