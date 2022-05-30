#include "libft.h"

int	ft_tolower(int c)
{
	if ((c > 64) && (c < 91))
		c += 32;
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(int argc, char **argv)
// {
//     printf("%d", ft_tolower(*argv[1]));
//     printf("%d", tolower(*argv[1]));
// }
