CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC_DIR = mandatory
SRCS = $(addprefix $(SRC_DIR)/, \
    ft_parcing.c \
    ft_split.c \
    ft_strdup.c \
    get_next_line.c \
    get_next_line_utils.c \
    parcing_utils.c \
    parcing_utils1.c \
    parcing_utils2.c \
    ft_putimage.c \
    ft_util.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)

MLX_PATH = ./mlx
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(SRC_DIR) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re