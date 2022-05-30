#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		secondex;
	char	*newstr;

	index = 0;
	secondex = 0;
	newstr = malloc(sizeof(*newstr) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1[index])
	{
		newstr[index] = s1[index];
		index++;
	}
	while (s2[secondex])
	{
		newstr[index + secondex] = s2[secondex];
		secondex++;
	}
	newstr[index + secondex] = '\0';
	return (newstr);
}

// int main()
// {
//     //char strong[] = "jelijpe";
//     //char strung[] = "Islijp";
// 	char	s1[] = "lorem ipsum";
// 	char	s2[] = "dolor sit amet";
// 	s2[1] = '\0';
//     printf("%s", ft_strjoin(s1, s2));
// }
