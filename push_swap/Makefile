# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mattif <mattif@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 17:21:10 by mattif            #+#    #+#              #
#    Updated: 2022/05/18 16:37:14 by mattif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CHECKER = checker

CFLAGS = -Wall -Wextra -Werror

SRC =	check_utils1.c \
		check_utils3.c \
		get_utils.c \
		sorting_2_5.c \
		args_checker.c \
		check_utils2.c \
		creating_stacks.c \
		push_swap.c \
		sorting_1.c \
		sorting_2.c \
		sorting_utils.c \
		sorting_utils_2.c \
		moves.c \
		
SRCB =	checker.c \
		checker_utils.c \
		moves.c \
		args_checker.c \
		check_utils1.c \
		check_utils2.c \
		check_utils3.c \
		sorting_utils.c \
		sorting_utils_2.c \
		creating_stacks.c \

OBJS = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $@

bonus : $(CHECKER) $(NAME)

$(CHECKER) : $(OBJB)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJB)

fclean: clean
	rm -rf $(NAME) $(CHECKER)

re : fclean all