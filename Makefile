CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \

OBJ = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

make: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) 

clean: 
	rm -f *.o
























































## Variables
#NAME = libft.a
#SRC = $(wildcard *.c)
#OBJ = $(SRC:.c=.o)
#CC = cc
#CFLAGS = -Wall -Wextra -Werror
#AR = ar
#ARFLAGS = rcs
#RM = rm -f

## Default rule
#all: $(NAME)

## Create the static library
#$(NAME): $(OBJ)
#	$(AR) $(ARFLAGS) $@ $^

## Compile .c files into .o files
#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@ -g

## Create the shared library
#so: $(OBJ)
#	$(CC) -shared -o libft.so $(OBJ)

## Remove object files
#clean:
#	$(RM) $(OBJ)

## Remove library and object files
#fclean: clean
#	$(RM) $(NAME) libft.so

#debug: clean
#	$(CC) $(CFLAGS) $(SRC) -g -o a.out

## Rule to recompile everything
#re: fclean all

#.PHONY: all clean fclean re so