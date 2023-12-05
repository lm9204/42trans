CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = pipex
SRC = pipex.c
HEADER = pipex.h

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CC) $(FLAGS) $< -o $@

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY: all fclean re