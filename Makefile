NAME=push_swap

CFLAGS= -Wall -Wextra -Werror

CC= cc

SRC= ft_putchar.c ft_error.c fill_arr.c fill_stack.c quick_sort.c run.c \
	 utils.c add_back.c add_front.c create_new.c iseq.c swap_num.c \
	 get_last.c

OBJ= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) main.c $(OBJ) -o $(NAME) -fsanitize=address -g

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
