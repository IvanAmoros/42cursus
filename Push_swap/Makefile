NAME = push_swap
BONUS = push_swap_bonus

LIB_DIR = ./Libft/
LIB = ${LIB_DIR}libft.a

SRC = src/push_swap.c \
		utils/check_args.c

OBJ_DIR = obj/


OBJ = ${addprefix ${OBJ_DIR}, ${SRC:.c=.o}}
DPS = ${addsuffix .d, ${basename ${OBJ}}}

SRC_BNS = push_swap_bonus.c
OBJ_BNS = ${addprefix ${OBJ_DIR}, ${SRC_BNS:.c=.o}}
DPS_BNS = ${addsuffix .d, ${basename ${OBJ_BNS}}}


CFLAGS = -Wall -Wextra -Werror
XFLAGS = -fsanitize=address -g3
RM = rm -rf

${OBJ_DIR}%.o: %.c Makefile
	mkdir -p ${dir $@}
	${CC} -MT $@ -MMD ${CFLAGS} -c $< -o $@

all: makelib ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${XFLAGS} -I ${LIB_DIR} ${OBJ}  -o ${NAME}

bonus: makelib ${BONUS}

${BONUS}: ${OBJ_BNS}
	${CC} ${CFLAGS} ${OBJ_BNS} ${LIB} -o ${BONUS}

makelib:
	make -C ${LIB_DIR}

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIB_DIR}

re: fclean all

-include ${DPS}
-include ${DPS_BNS}

.PHONY: all bonus makelib clean fclean re
