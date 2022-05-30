#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int main()
// {
// 	char s[] = "bazooka";
// 	ft_putendl_fd(s, 1);
// 	printf("charmander\n");
// }
