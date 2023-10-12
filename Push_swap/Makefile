NAME = push_swap

LIB_DIR = ./lib/

LIB_FT_DIR = ./Libft/
LIB_FT = ${LIB_FT_DIR}libft.a

SRC =	src/push_swap.c \
		src/swap.c \
		src/push.c \
		src/rotate.c \
		src/reverse_rotate.c \
		src/simple_sort.c \
		src/complex_sort.c\
		utils/check_args.c \
		utils/error.c \
		utils/utils.c \
		utils/stack_functions.c \
		utils/sort_utils.c

OBJ_DIR = obj/

INC = -I${LIB_FT_DIR} -I${LIB_DIR}


OBJ = ${addprefix ${OBJ_DIR}, ${SRC:.c=.o}}
DPS = ${addsuffix .d, ${basename ${OBJ}}}

CFLAGS = -Wall -Wextra -Werror
XFLAGS = -fsanitize=address -g3
RM = rm -rf

${OBJ_DIR}%.o: %.c Makefile
	mkdir -p ${dir $@}
	${CC} -MT $@ -MMD ${CFLAGS} ${INC} -c $< -o $@

all: makelib ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${XFLAGS} ${LIB_FT} ${OBJ}  -o ${NAME}

makelib:
	make -C ${LIB_FT_DIR}

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIB_FT_DIR}

re: fclean all

-include ${DPS}

.PHONY: all makelib clean fclean re
