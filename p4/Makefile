# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/05 00:59:17 by gedemais          #+#    #+#              #
#    Updated: 2019/04/05 15:07:51 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

NAME = p_5

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB_PATH = libft/

LIB = libft/libft.a

LIBIA = libia/libia.a

SRCS_NAME = main.c\
			check_win.c\
			generate_weight.c\
			playing.c\
			prepare_nw.c\
			train.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS_PATH = obj/

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

all : $(LIB) $(NAME)

$(NAME) : $(LIB) $(LIBIA) $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBIA)
		@echo "$(GRE)Done !$(DEF)"

$(LIB) : $(LIB_PATH)
		@echo "Making $(RED)Libft$(DEF)..."
		@make re -C $(LIB_PATH)

$(LIBIA) : libia/
		@make re libia/

$(OBJS) : $(SRCS)
		@mkdir -p $(OBJS_PATH)
		@echo "Making $(CYA)p_5$(DEF)..."
		@$(CC) $(CFLAGS) -c $(SRCS)
		@mv $(OBJS_NAME) obj/

fsanitize :
	gcc -g3 -fsanitize=address $(SRCS) $(LIB)

clean : 
	@rm -rf obj/
	@make clean -C $(LIB_PATH)

fclean : clean
	@make fclean -C $(LIB_PATH)
	@rm -rf $(NAME)

re : fclean all
