#include "libft.h"

int	ft_toupper(int c)
{
	if ((c > 96) && (c < 123))
		c -= 32;
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(int argc, char **argv)
// {
//     printf("%d", ft_toupper(*argv[1]));
//     printf("%d", toupper(*argv[1]));
// }
