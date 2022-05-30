#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haydex;
	size_t	ndldex;

	haydex = 0;
	ndldex = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	while ((haydex < len) && haystack[haydex])
	{
		while (haystack[haydex] == needle[ndldex])
		{
			ndldex++;
			if (needle[ndldex] == '\0')
				return ((char *) &haystack[haydex - ndldex + 1]);
			haydex++;
			if (haydex >= len)
				return (NULL);
		}
		haydex -= ndldex;
		ndldex = 0;
		haydex++;
	}
	return (NULL);
}

// int main()
// {
//     printf("%s\n", ft_strnstr("asdf", "sd", -1));
//     printf("%s\n", strnstr("asdf", "sd", -1));
// }
// int main()
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	printf("%s\n", ft_strnstr(haystack, needle, -1));
// 	printf("%s\n", strnstr(haystack, needle, -1));
// }
