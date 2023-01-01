# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 12:41:19 by abeihaqi          #+#    #+#              #
#    Updated: 2022/12/16 12:41:31 by abeihaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

HEADER = ./

CFLAGS = -Wall -Wextra -Werror -I $(HEADER)

SRCS =	./get_next_line.c		\
		./get_next_line_utils.c	\

OBJS = $(SRCS:.c=.o)

CC = cc

$(NAME):$(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
