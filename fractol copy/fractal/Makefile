CC = gcc
CFLAGS  = -g3 -Werror -Wall -Wextra
NAME = fractol
SRC = main.c fractol.c controls.c
OBJ = $(SRC:.c=.o)

HEADERS		= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBFT		= ../lib/libft
LIBMLX		= ../lib/MLX42
LIBS		= -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a

all : libft libmlx $(NAME)

libft:
	@$(MAKE) -s -C $(LIBFT)

libmlx:
	@$(MAKE) -s -C $(LIBMLX)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	
clean:
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(LIBMLX) clean
	rm -f $(OBJ)

fclean:
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(LIBMLX) fclean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: clean fclean all re
