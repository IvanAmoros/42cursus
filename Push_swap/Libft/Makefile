# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 13:36:17 by iamoros-          #+#    #+#              #
#    Updated: 2023/10/12 20:02:16 by iamoros-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

RM = rm -rf

OBJ = ${addprefix ${OBJ_DIR}, ${SRC:.c=.o}}

DEPS = ${addsuffix .d, ${basename ${OBJ}}}

OBJ_DIR = obj/

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

${OBJ_DIR}%.o: %.c Makefile
	mkdir -p ${dir $@}
	${CC} -MT $@ -MMD ${CFLAGS} ${INC} -c $< -o $@

$(NAME): $(OBJ)
	ar -crs $@ $(OBJ)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re
