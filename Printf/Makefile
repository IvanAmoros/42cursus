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

# Default rule - this is executed when `make` is run without arguments
all: $(NAME)

# Rule to create object files
$(OBJ_DIR)%.o: %.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $@ $^

# Rule to clean the build
clean:
	$(RM) $(OBJ) $(DEPS)
	@echo "You have cleaned all the .o and .d files"

# Rule to fully clean the build
fclean: clean
	$(RM) -r $(OBJ_DIR)
	@echo "Cleaned the object directory and also .a files"

# Rule to re-build everything
re: fclean all

# Include the dependency files
-include $(DEPS)

# Declare phony targets
.PHONY: all clean fclean re

# Disable built-in rules
.SUFFIXES:
