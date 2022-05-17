# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 22:24:12 by rvrignon          #+#    #+#              #
#    Updated: 2022/05/17 03:13:23 by rvrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/*.c

SRC =  	ft_printf.c main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) all -C libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	@echo "Generating obj..."
	$(CC) -c $(CFLAGS) $^
	@echo "\033[0m"

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(TEST) a.out

re: fclean all

bonus :