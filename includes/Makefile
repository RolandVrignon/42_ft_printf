# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 15:15:57 by rvrignon          #+#    #+#              #
#    Updated: 2022/05/18 16:31:22 by rvrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = includes.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =  	ft_printf.c utils_one.c utils_two.c utils_three.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	@echo "Generating obj..."
	$(CC) -c $(CFLAGS) $^
	@echo "\033[0m"

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TEST) a.out *.o

re: fclean all

bonus :