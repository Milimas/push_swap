# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 12:39:58 by abeihaqi          #+#    #+#              #
#    Updated: 2022/12/16 12:42:08 by abeihaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

BONUS= checker

CFLAGS= -Wall -Wextra -Werror

CC= cc

DIR = src/
LIB = libft.a
LIB_DIR = libft/
GL = get_next_line.a
GL_DIR = get_next_line/
OBJ_DIR = obj/

INCLUDE = -I include/	\
		  -I $(LIB_DIR)	\
		  -I $(GL_DIR)	\

SRC_FILES = fill_arr.c				\
			fill_stack.c			\
			create_new.c			\
			add_back.c				\
			get_last.c				\
			quick_sort.c			\
			swap_num.c				\
			run.c					\
			iseq.c					\
			utils.c					\
			add_front.c				\
			exit_on_error.c			\
			init_struct.c			\
			is_sorted.c				\
			sort_stack.c			\
			get_stacksize.c			\
			short_sort.c			\
			sort_3.c				\
			set_value_from_index.c	\

BSRC_FILES =	fill_arr.c		\
				fill_stack.c	\
	 			create_new.c	\
				add_back.c		\
				swap_num.c		\
				iseq.c			\
				utils.c			\
				add_front.c		\
				exit_on_error.c	\
				init_struct.c	\
				get_last.c		\
				quick_sort.c	\

SRCS = $(addprefix $(DIR), $(SRC_FILES))
BSRCS = $(addprefix $(DIR), $(BSRC_FILES))

OBJ= $(SRCS:$(DIR)%.c=$(OBJ_DIR)%.o)
BOBJ= $(BSRCS:$(DIR)%.c=$(OBJ_DIR)%.o)

$(NAME): $(OBJ) $(LIB) $(GL)
	@echo Compiling $@
	@$(CC) $(CFLAGS) main.c $(OBJ) $(LIB) -o $(NAME)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"

$(OBJ_DIR)%.o:$(DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo Compiling $@
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"


$(LIB):
	@echo Compiling $@
	@$(MAKE) -C $(LIB_DIR)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"
	@mv $(LIB_DIR)$(LIB) .

$(GL):
	@echo Compiling $@
	@$(MAKE) -C $(GL_DIR)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"
	@mv $(GL_DIR)$(GL) .

all: $(NAME) $(BONUS)

$(BONUS): $(BOBJ) $(LIB) $(GL)
	@echo Compiling $@
	@$(CC) $(CFLAGS) checker_bonus.c $(BOBJ) $(LIB) $(GL) -o $(BONUS)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"

bonus: $(BONUS)
	@echo Compiling $@
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(OBJ_DIR) "\033[31;1m"Removed"\033[0m"
	@$(MAKE) clean -C $(LIB_DIR)
	@echo $(LIB_DIR) "\033[32;1m"Cleaned"\033[0m"
	@$(MAKE) clean -C $(GL_DIR)
	@echo $(GL_DIR) "\033[32;1m"Cleaned"\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) "\033[31;1m"Removed"\033[0m"
	@rm -f $(BONUS)
	@echo $(BONUS) "\033[31;1m"Removed"\033[0m"
	@rm -f $(LIB)
	@echo $(LIB) "\033[31;1m"Removed"\033[0m"
	@rm -f $(GL)
	@echo $(GL) "\033[31;1m"Removed"\033[0m"
	@echo push_swap "\033[32;1m"Cleaned"\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
