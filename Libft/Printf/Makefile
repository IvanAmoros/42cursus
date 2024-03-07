# Compiler
CC = cc

# Name of the library
NAME = libftprintf.a

# Source files
SRC = ft_printf.c \
	src/ft_character.c \
	src/ft_printpercent.c \
	src/ft_checkpercent.c \
	src/ft_putnbr.c \
	src/ft_printstr.c \
	src/ft_unsputnbr.c \
	src/ft_printhexa.c \
	src/ft_pointers.c

# Object directory
OBJ_DIR = obj/

# Object files
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Dependency files
DEPS = $(OBJ:.o=.d)

# Compilation flags
CFLAGS = -Wall -Werror -Wextra -MMD

# Include path
INC = -I./

# ANSI color codes
COLOR_GREEN = \033[32m
COLOR_RED = \033[31m
COLOR_RESET = \033[0m

# Default rule - this is executed when `make` is run without arguments
all: $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) has been built successfully.$(COLOR_RESET)"

# Rule to create object files
$(OBJ_DIR)%.o: %.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled $< into $@$(COLOR_RESET)"

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $@ $^
	@echo "$(COLOR_GREEN)$(NAME) has been created successfully.$(COLOR_RESET)"

# Rule to clean the build
clean:
	$(RM) $(OBJ) $(DEPS)
	@echo "$(COLOR_RED)You have cleaned all the .o and .d files.$(COLOR_RESET)"

# Rule to fully clean the build
fclean: clean
	$(RM) -r $(OBJ_DIR) $(NAME)
	@echo "$(COLOR_RED)Cleaned the object directory and also .a files.$(COLOR_RESET)"

# Rule to re-build everything
re: fclean all

# Include the dependency files
-include $(DEPS)

# Declare phony targets
.PHONY: all clean fclean re

# Disable built-in rules
.SUFFIXES:
