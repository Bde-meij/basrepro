#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(int argc, char **argv)
// {
//     (void)  argc;
//     printf("%d", ft_isalnum(*argv[1]));
//     printf("%d", isalnum(*argv[1]));
// }
