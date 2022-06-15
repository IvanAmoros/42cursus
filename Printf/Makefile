# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 13:36:17 by iamoros-          #+#    #+#              #
#    Updated: 2022/06/15 18:23:37 by iamoros-         ###   ########.fr        #
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
	Functions/ft_pointers.c
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
HEAD = ft_printf.h
CFLAGS = -Wall -Werror -Wextra -MMD

%.o : %.c 
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ) 
	ar -crs $@ $(OBJ)

clean:
	@$(RM) $(OBJ) 
	@$(RM) $(DEPS)
	@echo You have cleaned all the .o/.d

fclean: clean
	@$(RM) $(NAME)
	@echo and also .a

re: fclean all

.PHONY: all clean fclean re
