# Target executable name
NAME =	fractol

# Makefile
MKF =	Makefile

# Source files
SRC =	src/main.c \
		src/flags.c

# Utility source file
UTILS = src/utils/window.c \
		src/utils/initialize.c

# Source directories
SRC_DIR = src/
UTILS_DIR = utils/
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

# Dependency files
ALL_DEPS = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)
ALL_DEPS += $(UTILS:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)

# Library files
LIBFT = inc/Libft/libft.a
MAKE_LIBFT = inc/Libft
MLX = inc/mlx/libmlx.a
MAKE_MLX = inc/mlx

# Compiler and flags
GCC = gcc -O3
FLAGS = -Wall -Werror -Wextra -MMD -MP -I$(DIR_HEDS)

# Compiler and linker flags for MiniLibX
MINILIBXCC := -I mlx -L $(DIR_MLX) -lmlx

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
$(NAME): $(OBJ_SRC) $(OBJ_UTILS)
	@$(GCC) $(FLAGS) $^ $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $@

# Phony target to build libraries
$(LIBFT):
	@$(MAKE) -C $(MAKE_LIBFT)
$(MLX):
	@$(MAKE) -C $(MAKE_MLX)

# Rule to build object files from source files and utility files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MKF) $(HEADER_FRAC)
	@mkdir -p $(@D)
	@$(GCC) $(FLAGS) -I$(DIR_HEDS) -c $< -o $@

# Include dependency files
-include $(ALL_DEPS)
