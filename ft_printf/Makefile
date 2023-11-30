CC = cc
HEADER = ft_printf.h
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_handle.c
LIB_DIR = libft
LIB_HEADER = libft.h
LIB = libft.a
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(LIB_DIR)/$(LIB) $(OBJS)
	ar crs $(NAME) $(NAME) $(OBJS)

%.o : %.c $(HEADER) 
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes 

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB) ./$(NAME)

$(LIB_DIR) :
	$(MAKE) -C $@ fclean

clean :
	rm -rf $(OBJS)

fclean : $(LIB_DIR)
	rm -rf $(OBJS)
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean re fclean $(LIB_DIR)