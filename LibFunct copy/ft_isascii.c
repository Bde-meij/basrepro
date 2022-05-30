#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 0177)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(int argc, char **argv)
// {
//     printf("%d", ft_isascii(*argv[1]));
//     printf("%d", isascii(*argv[1]));
// }
