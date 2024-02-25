CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -MP -g 
SRCS = solong.c movement.c render.c map.c map_parse.c render_map.c sprite.c \
		solong_utils.c
SRCS_BONUS = solong_bonus.c movement_bonus.c render_bonus.c map_bonus.c \
		map_parse_bonus.c render_map_bonus.c sprite_bonus.c solong_utils_bonus.c \
		enemy_bonus.c enemy_utils_bonus.c enemy_movement_bonus.c queue_bonus.c \
		render_utils_bonus.c
LIB_DIR = libft
LIB_HEADER = libft.h
LIB = libft.a
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = so_long

all : $(NAME)
bonus : .bonus

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) $(FLAGS) $(OBJS) -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

.bonus : $(OBJS_BONUS) $(LIB_DIR)/$(LIB)
	$(CC) $(FLAGS) $(OBJS_BONUS) -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)

$(LIB_DIR) :
	$(MAKE) -C $@ fclean

clean : $(LIB_DIR)
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	rm -rf $(SRCS:.c=.d)
	rm -rf $(SRCS_BONUS:.c=.d)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : fclean all

.PHONY: all bonus clean re fclean $(LIB_DIR)