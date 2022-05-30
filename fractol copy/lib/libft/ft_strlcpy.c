#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((src[index]) && (index < (dstsize - 1)))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

// int main()
// {
//     char desti[] = "kks";
//     char sork[] = "fffcsfjdjdfgj";
//     printf("%lu\n", ft_strlcpy(desti, sork, 5));
//     printf("%lu\n", strlcpy(desti, sork, 5));
// }
