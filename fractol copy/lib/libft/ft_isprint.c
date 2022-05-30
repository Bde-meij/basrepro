#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 040) && (c < 0177))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(int argc, char **argv)
// {
//     (void)  argc;
//     printf("%d", ft_isprint(*argv[1]));
//     printf("%d", isprint(*argv[1]));
// }
//als +1 of +2 gelijk is aan iets wat door 10 te delen is
// if(((argv + 001) % 10 == 0) || ((argv + 002) % 10 == 0))
//     return 0;
