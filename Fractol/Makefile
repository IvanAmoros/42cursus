CC			= gcc

OBJ_DIR 	= obj/

OBJS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAIN_FILES)))

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)