# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 22:24:12 by rvrignon          #+#    #+#              #
#    Updated: 2022/05/18 15:22:53 by rvrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =  	main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) all -C libft
	cp libft/libft.a includes/includes.a
	$(MAKE) all -C includes
	cp includes/includes.a $(NAME)
	$(CC) $(CFLAGS) $(SRC) $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	@echo "Generating obj..."
	$(CC) -c $(CFLAGS) $^
	@echo "\033[0m"

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./includes
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./includes
	rm -f $(NAME) $(TEST) a.out *.o

re: fclean all

bonus :