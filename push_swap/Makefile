CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -MP -g -fsanitize=address
SRCS = push_swap.c push_swap_fnc.c base.c list.c
CHECKER_SRCS = checker.c push_swap_fnc.c checker_utils.c
# SRCS_BONUS = 
LIB_DIR = libft
LIB_HEADER = libft.h
LIB = libft.a
OBJS = $(SRCS:.c=.o)
OBJS_CHECKER = $(CHECKER_SRCS:.c=.o)
# OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = push_swap
CHECKER = checker
# BONUS = .bonus

all : $(NAME)
# bonus : $(BONUS)
checker : $(CHECKER)

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) $(FLAGS) $^ -o $(NAME)

$(CHECKER) : $(OBJS_CHECKER) $(LIB_DIR)/$(LIB)
	$(CC) $(FLAGS) $^ -o $(CHECKER)

# $(BONUS) : $(OBJS_BONUS) $(LIB_DIR)/$(LIB)
# 	$(CC) $(FLAGS) $^ -o $@
# 	cp $@ $(NAME)

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
	rm -rf $(BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all checker bonus clean re fclean $(LIB_DIR)