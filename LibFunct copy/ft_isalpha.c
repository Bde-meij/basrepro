#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(int argc, char **argv)
// {
//     (void)  argc;
//     printf("%d", ft_isalpha(*argv[1]));
//     printf("%d", isalpha(*argv[1]));
// }
