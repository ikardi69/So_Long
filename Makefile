CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
BONUS_NAME = so_long_bonus

MANDATORY_DIR = mandatory/
BONUS_DIR = bonus/

SRCS = $(wildcard $(MANDATORY_DIR)*.c)
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(wildcard $(BONUS_DIR)*.c)
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