# Target executable name
NAME =	fractol

# Makefile
MKF =	Makefile

# Source files
SRC =	src/main.c

# Utility source file
UTILS = src/utils/window.c \
		src/utils/ft_atof.c \
		src/utils/colors.c \
		src/utils/mouse_hooks.c \
		src/utils/key_hooks.c \
		src/utils/initialize.c

# Utility source file
FRACTALS =	src/fractals/mandelbrot.c \
			src/fractals/julia.c

# Source directories
SRC_DIR = src/
UTILS_DIR = utils/
FRAC_DIR = fractals/
OBJ_DIR = obj/

# Header files
HEADER_FRAC = inc/headers/fractol.h

# Library directories
DIR_LIBFT = inc/Libft
DIR_MLX = inc/mlx
DIR_HEDS = inc/headers

# Object files
OBJ_SRC = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_UTILS = $(UTILS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_FRAC = $(FRACTALS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Dependency files
ALL_DEPS = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)
ALL_DEPS += $(UTILS:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)
ALL_DEPS += $(FRACTALS:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)

# Library files
LIBFT = inc/Libft/libft.a
MAKE_LIBFT = inc/Libft
MLX = inc/mlx/libmlx.a
MAKE_MLX = inc/mlx

# Compiler and flags
CC = cc
CFLAGS = -O3 -Wall -Werror -Wextra -MMD -MP -I$(DIR_HEDS) -I$(MAKE_LIBFT)

# Compiler and linker flags for MiniLibX
MINILIBXCC := -I $(DIR_MLX) -L $(DIR_MLX) -lmlx

# Linker flags for OpenGL and AppKit frameworks
OPENGL := -framework OpenGL -framework AppKit

# Rule to build all targets
all: $(LIBFT) $(MLX) $(NAME)

# Rule to clean object files
clean:
	@rm -rf $(OBJ_DIR)

# Rule to clean object files and the executable
fclean: clean
	@rm -f $(NAME)

# Rule to clean all including libraries
fcleanall:
	@$(MAKE) fclean -C $(MAKE_LIBFT)
	@$(MAKE) clean -C $(MAKE_MLX)
	@$(MAKE) fclean

# Rule to remake the project
re: fclean all

# Rule to remake the project including cleaning libraries
reall: fcleanall all

# Rule to link the executable
$(NAME): $(OBJ_SRC) $(OBJ_UTILS) $(OBJ_FRAC)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $@

# Phony target to build libraries
$(LIBFT):
	@$(MAKE) -C $(MAKE_LIBFT)
$(MLX):
	@$(MAKE) -C $(MAKE_MLX)

# Rule to build object files from source files and utility files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MKF) $(HEADER_FRAC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean fclean fcleanall re reall

# Include dependency files
-include $(ALL_DEPS)