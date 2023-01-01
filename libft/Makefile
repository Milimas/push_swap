# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 03:11:35 by abeihaqi          #+#    #+#              #
#    Updated: 2022/12/16 12:41:45 by abeihaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./

CFLAGS = -Wall -Wextra -Werror -I $(HEADER)

SRCS = ./ft_atoi.c	\
	ft_calloc.c		\
	ft_isdigit.c	\
	ft_memcmp.c		\
	ft_memcpy.c		\
	ft_memset.c		\
	ft_putstr.c		\
	ft_split.c		\
	ft_strchr.c		\
	ft_strlen.c		\
	ft_substr.c		\

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
