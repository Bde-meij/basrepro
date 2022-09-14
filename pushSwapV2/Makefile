NAME = push_swap
CC	= gcc
SRC = pushswap.c \
inspection.c \
utilities.c \
hardsort.c \
commands.c \
logic.c

OBJFILES = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
CHECKER = ./checkermap/

all	: $(NAME)

$(NAME) : $(OBJFILES)
	@$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)

bonus: 
	make all
	@$(MAKE) -s -C $(CHECKER)

clean:
	rm -f $(OBJFILES)
	cd $(CHECKER) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(CHECKER) && make fclean

re: fclean all

.PHONY: clean fclean bonus all