# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 11:04:01 by jgarcia           #+#    #+#              #
#    Updated: 2022/09/01 11:14:14 by jgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CFLAGS=-Wall -Wextra -Werror -g
CC=gcc
SOURCE=main.c stack.c parser.c ft_atoi.c
OBJ=$(SOURCE:.c=.o)
RM= rm -f

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

norme:
	norminette $(SOURCE)
	norminette *.h

.PHONY: all re clean fclean norme