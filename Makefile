# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 03:23:53 by gedemais          #+#    #+#              #
#    Updated: 2019/09/06 03:16:06 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Weverything -Wall -Werror -Wextra

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g3 -fsanitize=address
endif

LIB_PATH=libft/
LIB=$(LIB_PATH)libft.a

NAME=lem-in

SRCS_PATH=srcs/
SRCS_NAME=	main.c\
			bfs.c\
			list.c\
			sort_paths.c\
			treat_paths.c\
			output_buffer.c\
			edmond_karp.c\
			store_paths.c\
			crossing.c\
			read_fd_zero.c\
			parsing.c\
			make_graph.c\
			make_matrix.c\
			load_line.c\
			is_disjoint.c\
			room_err_cases.c\
			count.c\
			free.c\
			states.c

SRCS=$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH=objs/
OBJS_NAME=$(SRCS_NAME:.c=.o)

OBJS=$(addprefix $(OBJS_PATH), $(OBJS_NAME))

INC_PATH=includes/
INC_NAME=main.h
INC=$(addprefix $(INC_PATH), $(INC_NAME))

all : $(LIB) $(NAME)

$(LIB) : $(LIB_PATH)
	@make -C $(LIB_PATH)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) -I $(INC_PATH) $(OBJS)  $(LIB)
	@echo "Done !"

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(INC)
	@echo "Making lem_in..."
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(INC_PATH)
	@mv $(OBJS_NAME) $(OBJS_PATH)

clean :
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJS_PATH)

fclean : clean
	@make -C $(LIB_PATH) fclean
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM/

re : fclean all
