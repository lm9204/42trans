CC = cc
HEADER = pipex.h
FLAGS = -Wall -Wextra -Werror -g
SRCS = pipex.c pipex_utils.c
LIB_DIR = libft
LIB_HEADER = libft.h
LIB = libft.a
OBJS = $(SRCS:.c=.o)
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) $(FLAGS) -g $^ -o $@ 

%.o : %.c $(HEADER) 
	$(CC) $(FLAGS) -g -c $< -o $@ -Iincludes 

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)

$(LIB_DIR) :
	$(MAKE) -C $@ fclean

clean :
	rm -rf $(OBJS)

fclean : $(LIB_DIR)
	rm -rf $(OBJS)
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean re fclean $(LIB_DIR)