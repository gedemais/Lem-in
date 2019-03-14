# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 16:42:45 by gedemais          #+#    #+#              #
#    Updated: 2019/03/13 17:55:22 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lmbf

CC = gcc

CFLAGS = -O1 -O2 -O3 -Wall -Werror -Wextra

LIB = libft/libft.a

SRCS_PATH = srcs/

SRCS_NAME = 	main.c \
		ft_parsing.c \
		ft_print.c \
		ft_loadmap.c

OBJS = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(OBJS) : $(SRCS) $(LIB)
	@$(CC) $(CFLAGS) -c $(SRCS)

$(LIB) : libft/
	@make -C libft/

clean :
	@rm -rf $(OBJS)
	@make clean -C libft/

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft/

re : fclean all
