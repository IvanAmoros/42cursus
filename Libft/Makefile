# VPATH specifies the search paths for source files
VPATH = Printf/src

# Name of the final library
NAME = libft.a

# Source files for both libft and Printf
SRC = ft_isalnum.c		\
      ft_isalpha.c		\
      ft_isdigit.c		\
      ft_isascii.c		\
      ft_isprint.c		\
      ft_strlen.c		\
      ft_memset.c		\
      ft_bzero.c		\
      ft_memcpy.c		\
      ft_memmove.c		\
      ft_strlcpy.c		\
      ft_strlcat.c		\
      ft_toupper.c		\
      ft_tolower.c		\
      ft_strchr.c		\
      ft_strrchr.c		\
      ft_strncmp.c		\
      ft_memchr.c		\
      ft_memcmp.c		\
      ft_strnstr.c		\
      ft_atoi.c			\
      ft_calloc.c		\
      ft_strdup.c		\
      ft_substr.c		\
      ft_strjoin.c		\
      ft_strtrim.c		\
      ft_split.c		\
      ft_itoa.c			\
      ft_strmapi.c		\
      ft_striteri.c		\
      ft_putchar_fd.c	\
      ft_putstr_fd.c	\
      ft_putendl_fd.c	\
      ft_putnbr_fd.c	\
      ft_lstnew.c		\
      ft_lstadd_front.c	\
      ft_lstsize.c		\
      ft_lstlast.c		\
      ft_lstadd_back.c	\
      ft_lstdelone.c	\
      ft_lstclear.c		\
      ft_lstiter.c		\
      ft_lstmap.c

# Additional source files specific to Printf
SRC += Printf/ft_printf.c			\
       Printf/src/ft_character.c	\
       Printf/src/ft_printpercent.c	\
       Printf/src/ft_checkpercent.c	\
       Printf/src/ft_putnbr.c		\
       Printf/src/ft_printstr.c		\
       Printf/src/ft_unsputnbr.c	\
       Printf/src/ft_printhexa.c	\
       Printf/src/ft_pointers.c

# Object directory
OBJ_DIR = obj/

# Object files for both libft and Printf
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Dependency files
DEPS = $(OBJ:.o=.d)

# Remove command
RM = rm -rf

# Compilation flags
CFLAGS = -Wall -Werror -Wextra

# Include path for both libft and Printf
INC = -I./ -I./Printf

# ANSI color codes
COLOR_GREEN = \033[32m
COLOR_RED = \033[31m
COLOR_RESET = \033[0m

# Default rule - build the library
all: $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) has been built successfully.$(COLOR_RESET)"

# Rule to create object files
$(OBJ_DIR)%.o: %.c Makefile
	mkdir -p $(@D)
	$(CC) -MT $@ -MMD $(CFLAGS) $(INC) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled $< into $@$(COLOR_RESET)"

# Rule to create the library
$(NAME): $(OBJ)
	ar -crs $@ $(OBJ)

# Rule to clean the build
clean:
	$(RM) $(OBJ_DIR)
	@echo "$(COLOR_RED)You have cleaned all the .o and .d files.$(COLOR_RESET)"
	$(MAKE) -C Printf clean

# Rule to fully clean the build
fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOR_RED)Cleaned the object directory and also .a files.$(COLOR_RESET)"
	$(MAKE) -C Printf fclean

# Rule to re-build everything
re: fclean all

# Include the dependency files
-include $(DEPS)

# Declare phony targets
.PHONY: all clean fclean re
