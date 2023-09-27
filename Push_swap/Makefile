NAME = push_swap
BONUS = push_swap_bonus

LIB_DIR = ./lib/

LIB_FT_DIR = ./Libft/
LIB_FT = ${LIB_FT_DIR}libft.a

SRC =	src/push_swap.c \
		src/swap.c \
		src/push.c \
		src/rotate.c \
		src/reverse_rotate.c \
		src/simple_sort.c \
		utils/check_args.c \
		utils/error.c \
		utils/utils.c \
		utils/stack_functions.c

OBJ_DIR = obj/

INC = -I${LIB_FT_DIR} -I${LIB_DIR}


OBJ = ${addprefix ${OBJ_DIR}, ${SRC:.c=.o}}
DPS = ${addsuffix .d, ${basename ${OBJ}}}

SRC_BNS = push_swap_bonus.c
OBJ_BNS = ${addprefix ${OBJ_DIR}, ${SRC_BNS:.c=.o}}
DPS_BNS = ${addsuffix .d, ${basename ${OBJ_BNS}}}


#CFLAGS = -Wall -Wextra -Werror
#XFLAGS = -fsanitize=address -g3
RM = rm -rf

${OBJ_DIR}%.o: %.c Makefile
	mkdir -p ${dir $@}
	${CC} -MT $@ -MMD ${CFLAGS} ${INC} -c $< -o $@

all: makelib ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${XFLAGS} ${LIB_FT} ${OBJ}  -o ${NAME}

bonus: makelib ${BONUS}

${BONUS}: ${OBJ_BNS}
	${CC} ${CFLAGS} ${OBJ_BNS} ${LIB_FT} -o ${BONUS}

makelib:
	make -C ${LIB_FT_DIR}

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIB_FT_DIR}

re: fclean all

-include ${DPS}
-include ${DPS_BNS}

.PHONY: all bonus makelib clean fclean re
