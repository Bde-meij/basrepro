#include "libft.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	index;
	int	sign;

	value = 0;
	index = 0;
	sign = 1;
	while ((str[index] == 32) || (str[index] >= 9 && str[index] <= 13))
		index++;
	if ((str[index] == '-') || (str[index] == '+'))
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while ((str[index] >= '0') && (str[index] <= '9'))
	{
		value *= 10;
		value += (str[index] - 48);
		index++;
	}
	return (value * sign);
}

// int main()
// {
//     const char str[] = "256345";
//     printf("%d\n", ft_atoi(str));
//     printf("%d\n", atoi(str));
// }
// (str[index] == '\n') || (str[index] == '\t')
// || (str[index] == '\v') || (str[index] == '\f') || (str[index] == '\r'))
