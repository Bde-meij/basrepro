/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:15 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:17 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*str1;
	unsigned const char		*str2;
	int						retval;
	int						index;

	str1 = s1;
	str2 = s2;
	retval = 0;
	index = 0;
	while (n)
	{
		retval = str1[index] - str2[index];
		if (retval != 0)
			return (retval);
		n--;
		index++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
//     char interestring[] = "asdfasdfhg";
//     char stringinterest[] = "asdfasdfgh";
//     printf("%d\n", ft_memcmp(interestring, stringinterest, 20));
//     printf("%d\n", memcmp(interestring, stringinterest, 20));
// }
