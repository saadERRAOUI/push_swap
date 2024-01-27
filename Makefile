NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap_utils.c push_swap.c push_swap_ops.c #In Progress...

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -fsanitize=address -g3 $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean

re: fclean all