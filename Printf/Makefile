# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 13:36:17 by iamoros-          #+#    #+#              #
#    Updated: 2022/06/13 20:20:10 by iamoros-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c \
	Functions/ft_character.c \
	Functions/ft_printpercent.c \
	Functions/ft_checkpercent.c \
	Functions/ft_putnbr.c \
	Functions/ft_printstr.c \
	Functions/ft_unsputnbr.c \
	Functions/ft_printhexa.c \
	Functions/ft_printmhexa.c \
	Functions/ft_pointers.c
RM = rm -f
OBJ = $(SRC:.c=.o)
DEPS = ft_printf.h
CFLAGS = -Wall -Werror -Wextra

%.o : %.c $(DEPS)
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	ar -crs $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
