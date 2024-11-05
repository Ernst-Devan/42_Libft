# Variables
NAME = libft.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

# Default rule
all: $(NAME)

# Create the static library
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

# Create the shared library
so: $(OBJ)
	$(CC) -shared -o libft.so $(OBJ)

# Remove object files
clean:
	$(RM) $(OBJ)

# Remove library and object files
fclean: clean
	$(RM) $(NAME) libft.so

debug: clean
	$(CC) $(CFLAGS) $(SRC) -g -o a.out

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re so