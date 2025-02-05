# Makefile for So Long Project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = so_long

# Source files
SRCS = ft_parcing.c \
       ft_split.c \
       ft_strdup.c \
       ft_strncmp.c \
       ft_substr.c \
       get_next_line.c \
       get_next_line_utils.c \
       parcing_utils.c \
       parcing_utils1.c \
       parcing_utils2.c \
       ft_putimage.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = so_long.h

# MLX library path
MLX_PATH = ./mlx

# MLX library and include flags
MLX_LIB = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

# Compilation targets
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

# Compiling source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Run the program
run: $(NAME)
	./$(NAME) map.ber

# Phony targets
.PHONY: all clean fclean re run