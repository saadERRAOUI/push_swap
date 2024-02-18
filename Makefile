#######################################################
# VARS     	 										  #
#######################################################
NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

#######################################################
# MANDATORY     									  #
#######################################################
SOURCES = push_swap_utils3.c push_swap_check.c push_swap_func.c push_swap_utils2.c push_swap_orch.c push_swap_sort.c push_swap_utils.c push_swap.c push_swap_ops.c get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

#######################################################
# OPERATIONS 										  #
#######################################################
all: $(NAME)

bonus: $(CHECKER)

clean:
	rm -f $(OBJECTS) $(B_OBJECTS) $(PTF_OBJECTS)

fclean: clean
	rm -f $(NAME) $(CHECKER) $(PRINTF)

re: fclean all

#######################################################
# FT_PRINTF											  #
#######################################################
OUTPUT_DIR = ft_printf

PTF_SOURCES = ft_printf/ft_print_base.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c

PTF_OBJECTS = $(patsubst ft_printf/%.c, $(OUTPUT_DIR)/%.o, $(PTF_SOURCES))

PRINTF = libftprintf.a

$(PRINTF): $(PTF_OBJECTS)
	ar -rc $(PRINTF) $(PTF_OBJECTS)

$(OUTPUT_DIR)/%.o: ft_printf/%.c
	mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#######################################################
# BONUS 											  #
#######################################################
B_SOURCES = push_swap_utils3.c push_swap_check.c push_swap_func.c push_swap_utils2.c push_swap_orch.c push_swap_sort.c push_swap_utils.c push_swap_ops.c \
get_next_line.c get_next_line_utils.c checker.c bonus_checker_ops.c

B_OBJECTS = $(B_SOURCES:.c=.o)

$(NAME): $(OBJECTS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJECTS) -L. -lftprintf -o $(NAME)

$(CHECKER): $(B_OBJECTS)
	$(CC) $(CFLAGS) $(B_OBJECTS) -L. -lftprintf -o $(CHECKER)
