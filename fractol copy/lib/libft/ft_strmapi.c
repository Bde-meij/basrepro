#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*returnar;

	index = ft_strlen(s);
	returnar = malloc(sizeof(*returnar) * (index + 1));
	if (!returnar)
		return (NULL);
	returnar[index] = '\0';
	while (index > 0)
	{
		index--;
		returnar[index] = f(index, s[index]);
	}
	return (returnar);
}
