/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:06 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:07 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countula(int n)
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

static int	checkn(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if ((n < 0) && (n != -2147483648))
	{
		n *= -1;
		write(fd, "-", 1);
		return (n);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		magnitude;
	int		charval;

	len = countula(n) - 1;
	magnitude = 1;
	n = checkn(n, fd);
	while (len)
	{
		magnitude *= 10;
		len--;
	}
	len = countula(n);
	while (len && (n != -2147483648))
	{
		charval = n / magnitude;
		charval += 48;
		write(fd, &charval, 1);
		charval -= 48;
		n -= (charval * magnitude);
		magnitude /= 10;
		len--;
	}		
}

// int	main()
// {
// 	ft_putnbr_fd(10000000, 1);
// 	printf("\n"); 
// 	ft_putnbr_fd(rand(), 1);
// 	printf("\n"); 
// 	ft_putnbr_fd(rand(), 1);
// 	printf("\n"); 
// 	ft_putnbr_fd(rand(), 1);
// 	printf("\n");
// 	ft_putnbr_fd(rand(), 1);
// 	printf("\n"); 
// 	ft_putnbr_fd(rand(), 1);
// 	printf("\n"); 
// printf("%d\n", rand()); printf("%d\n", rand());printf("%d\n", 
// rand());printf("%d\n", rand());printf("%d\n", rand());printf("%d\n", rand());
//}
// void	ft_putnbr_fd(int n, int fd)
// {
// 	write(fd, ft_itoa(n), ft_strlen(ft_itoa(n)));
// }
