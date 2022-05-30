#include "libft.h"

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len])
	{
		len++;
	}
	return (len);
}

// int main(int argc, char **argv)
// {
//     (void) argc;
//     argv++;
//     printf("%lu \n", ft_strlen(*argv));
//     printf("%lu", strlen(*argv));
// }
