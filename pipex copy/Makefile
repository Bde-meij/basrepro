NAME = pipex
CC	= gcc
SRC = pipex.c \
bonus_section.c \
protect_n_free.c \
paths_n_commands.c \
libmap/ft_atoi.c \
libmap/ft_bzero.c \
libmap/ft_calloc.c \
libmap/ft_isalnum.c \
libmap/ft_isalpha.c \
libmap/ft_isascii.c \
libmap/ft_isdigit.c \
libmap/ft_isprint.c \
libmap/ft_memchr.c \
libmap/ft_memcmp.c \
libmap/ft_memcpy.c \
libmap/ft_memmove.c \
libmap/ft_memset.c \
libmap/ft_strchr.c \
libmap/ft_strdup.c \
libmap/ft_strlcat.c \
libmap/ft_strlcpy.c \
libmap/ft_strlen.c \
libmap/ft_strncmp.c \
libmap/ft_strnstr.c \
libmap/ft_strrchr.c \
libmap/ft_tolower.c \
libmap/ft_toupper.c \
libmap/ft_substr.c \
libmap/ft_strjoin.c \
libmap/ft_strtrim.c \
libmap/ft_itoa.c \
libmap/ft_strmapi.c \
libmap/ft_split.c \
libmap/ft_striteri.c \
libmap/ft_putchar_fd.c \
libmap/ft_putstr_fd.c \
libmap/ft_putendl_fd.c \
libmap/ft_putnbr_fd.c \
libmap/ft_strlow.c \
nextline/get_next_line.c

OBJFILES = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
LIBFT = libmap/

all	: $(NAME)

$(NAME) : $(OBJFILES)
	@$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)
	cd $(LIBFT) && make

clean: 
	rm -f $(OBJFILES)
	cd $(LIBFT) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT) && make fclean

re: fclean all

.PHONY: clean fclean bonus all