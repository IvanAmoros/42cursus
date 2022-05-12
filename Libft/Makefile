# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 13:36:17 by iamoros-          #+#    #+#              #
#    Updated: 2022/05/12 01:17:34 by iamoros-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c
DEPS = libft.h
FLAGS = -Wall -Wextra -Werror -I $(DEPS)
RM = rm -f
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	ar -crs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:
	fclean
	clean
.PHONY: all clean fclean re
