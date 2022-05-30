#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(int argc, char **argv)
// {
//     (void)  argc;
//     printf("%d", ft_isdigit(*argv[1]));
//     printf("%d", isdigit(*argv[1]));
// }
