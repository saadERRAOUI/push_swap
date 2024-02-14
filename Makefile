NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap_check.c push_swap_func.c push_swap_utils2.c push_swap_orch.c push_swap_sort.c push_swap_utils.c push_swap.c push_swap_ops.c #In Progress...

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -L. -lftprintf -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean

re: fclean all