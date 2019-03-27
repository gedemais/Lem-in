NAME = libia.a

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

SRCS_NAME = display_info.c \
	   		activation.c \
	   		init_network.c \
	   		init_neurone.c

SRCS_PATH = srcs/

INC = includes/libia.h includes/neural_network.h

INC_PATH = includes/

FLAG = -Wall -Wextra -Werror

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	@echo "Making $(RED)$(SOU)Libia$(DEF)$(RED)...$(DEF)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GRE)Done !$(DEF)"

%.o: $(SRCS_PATH)%.c $(INC)
	@gcc $(FLAG) -c $< -o $@ -I $(INC_PATH)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)Libia$(DEF) deleted"
	@rm -rf $(NAME)

re: fclean all
