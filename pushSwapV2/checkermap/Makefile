NAME = checker
CC	= gcc
SRC = checker.c \
commands_bonus.c \
inspection_bonus.c \
libfuncts.c \
nextline/get_next_line.c \
nextline/get_next_line_utils.c

OBJFILES = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all	: $(NAME)

$(NAME) : $(OBJFILES)
	@$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean bonus all