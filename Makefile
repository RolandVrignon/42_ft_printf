# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 22:24:12 by rvrignon          #+#    #+#              #
#    Updated: 2022/05/18 22:09:55 by rvrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  	ft_printf.c includes/utils_one.c includes/utils_two.c includes/utils_three.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) all -C libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)

clean:		
			$(MAKE) clean -C ./libft
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re