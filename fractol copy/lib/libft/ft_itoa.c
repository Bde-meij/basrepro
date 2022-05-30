#include "libft.h"

static int	count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;

	len = count(n);
	if (n < 0)
	{
		if (n != -2147483648)
			n *= -1;
		len++;
	}
	s = ft_calloc(sizeof(*s), (len + 1));
	if (!s)
		return (NULL);
	s[0] = '-';
	if (n != -2147483648)
		n *= -1;
	while (len > 0)
	{
		len--;
		s[len] = -(n % 10) + 48;
		n /= 10;
		if (n == 0)
			break ;
	}
	return (s);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(100010001));
// 	printf("%s\n", ft_itoa(69420));
// 	printf("%s\n", ft_itoa(-69420));
// }
