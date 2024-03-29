# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 11:04:01 by jgarcia           #+#    #+#              #
#    Updated: 2022/11/22 23:36:35 by jgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CFLAGS=-Wall -Wextra -Werror -g3 -fanalyzer
CC=gcc
PRINTF=ft_printf/libftprintf.a
LINK=-Lft_printf -lftprintf
SOURCE=main.c stack.c parser.c ft_atoi.c ft_strlen.c sort.c ft_strdup.c ft_memcpy.c ft_strlcpy.c ft_substr.c ft_split.c tests.c
SOURCE+=operations.c partition.c memory_clean.c
OBJ=$(SOURCE:.c=.o)
RM= rm -f

all:$(NAME)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(OBJ) $(LINK) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C ft_printf
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

norme:
	norminette $(SOURCE)
	norminette *.h

.PHONY: all re clean fclean norme