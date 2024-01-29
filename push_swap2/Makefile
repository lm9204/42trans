CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -MP -g 
SRCS = push_swap.c push_swap_fnc.c base.c list.c radix.c radix_utils.c \
		push_swap_utils.c radix_low.c
CHECKER_SRCS = checker.c checker_fnc.c checker_utils.c checker_validate.c
LIB_DIR = libft
LIB_HEADER = libft.h
LIB = libft.a
OBJS = $(SRCS:.c=.o)
OBJS_CHECKER = $(CHECKER_SRCS:.c=.o)
NAME = push_swap
BONUS = checker

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) $(FLAGS) $^ -o $(NAME)

$(BONUS) : $(OBJS_CHECKER) $(LIB_DIR)/$(LIB)
	$(CC) $(FLAGS) $^ -o $(BONUS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)

$(LIB_DIR) :
	$(MAKE) -C $@ fclean

clean : $(LIB_DIR)
	rm -rf $(OBJS)
	rm -rf $(OBJS_CHECKER)
	rm -rf $(SRCS:.c=.d)
	rm -rf $(CHECKER_SRCS:.c=.d)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : fclean all

.PHONY: all bonus clean re fclean $(LIB_DIR)