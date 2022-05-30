#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*retstr;
	size_t		index;

	retstr = s;
	index = 0;
	while (n > 0)
	{
		if (retstr[index] == (char) c)
			return ((void *) retstr + index);
		index++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     int string[3] = {3, -1, 5};
//     printf("%s\n", ft_memchr(string, -1, 40));
//     printf("%s\n", memchr(string, -1, 40));
// }
