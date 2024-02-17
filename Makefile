NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

#mandatory files
SOURCES = push_swap_utils3.c push_swap_check.c push_swap_func.c push_swap_utils2.c push_swap_orch.c push_swap_sort.c push_swap_utils.c push_swap.c push_swap_ops.c

OBJECTS = $(SOURCES:.c=.o)

#bonus files
B_SOURCES = push_swap_utils3.c push_swap_check.c push_swap_func.c push_swap_utils2.c push_swap_orch.c push_swap_sort.c push_swap_utils.c push_swap_ops.c get_next_line.c get_next_line_utils.c checker.c bonus_checker_ops.c

B_OBJECTS = $(B_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -L. -lftprintf -o $(NAME)

CHECKER = checker

bonus: $(CHECKER)

$(CHECKER): $(B_OBJECTS)
	$(CC) $(CFLAGS) $(B_OBJECTS) -L. -lftprintf -o $(CHECKER)

clean:
	rm -f $(OBJECTS)

fclean: clean

re: fclean all