CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
BONUS_NAME = so_long_bonus

MANDATORY_DIR = mandatory/
BONUS_DIR = bonus/

SRCS = $(MANDATORY_DIR)my_util1.c \
		$(MANDATORY_DIR)my_util2.c \
		$(MANDATORY_DIR)my_util3.c \
		$(MANDATORY_DIR)my_util4.c \
		$(MANDATORY_DIR)my_util5.c \
		$(MANDATORY_DIR)my_util6.c \
		$(MANDATORY_DIR)my_util7.c \
		$(MANDATORY_DIR)my_util8.c \
		$(MANDATORY_DIR)my_util9.c \
		$(MANDATORY_DIR)my_util10.c \
		$(MANDATORY_DIR)so_long.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(BONUS_DIR)my_util1_bonus.c \
			$(BONUS_DIR)my_util2_bonus.c \
			$(BONUS_DIR)my_util3_bonus.c \
			$(BONUS_DIR)my_util4_bonus.c \
			$(BONUS_DIR)my_util5_bonus.c \
			$(BONUS_DIR)my_util6_bonus.c \
			$(BONUS_DIR)my_util7_bonus.c \
			$(BONUS_DIR)my_util8_bonus.c \
			$(BONUS_DIR)my_util9_bonus.c \
			$(BONUS_DIR)my_util10_bonus.c \
			$(BONUS_DIR)my_util11_bonus.c \
			$(BONUS_DIR)my_util12_bonus.c \
			$(BONUS_DIR)my_util13_bonus.c \
			$(BONUS_DIR)so_long_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

MLX_DIR = mlx/
MLX = $(MLX_DIR)libmlx_Linux.a
MLX_FLAGS = -Lmlx -lmlx_Linux -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX) $(MLX_FLAGS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re