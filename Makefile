NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj/
SRC_DIR = src/

SRC		:=	push_swap.c \
			input_check.c \
			list_utils.c \
			list_utils2.c \
			sorting_utils.c \
			sorting_utils2.c \
			sorting_utils3.c \
			utils.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ	= $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
HEADER = -I ./include -I ../LeakSanitizer 
LIBFT = ./libft/libft.a

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@ $(HEADER)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	cd libft && make
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	clear

clean:
	cd libft && make clean
	rm -rf $(OBJ_DIR)
	clear

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: all clean fclean re libft
