/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:13 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:14 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	index = 0;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	if (src >= dst)
	{
		while (index < len)
		{
			((char *) dst)[index] = ((char *) src)[index];
			index++;
		}
	}
	else
	{
		while (len)
		{
			len--;
			((char *) dst)[len] = ((char *) src)[len];
		}
	}
	return (dst);
}

// // #include <string.h>
// // #include <stdio.h>

// int main()
// {
// //     char stringeling[] = "ikbeneenstring";
// //     char garechar[] = "waarismijnstring";
// //     char *teststring1 = &stringeling[3];
// //     char *teststring2 = &garechar[3];
// //     printf("%s\n", memmove(teststring1, garechar, 5));
// //     printf("%s\n", memmove(stringeling, teststring2, 5));
// //     printf("%s\n", ft_memmove(teststring1, garechar, 5));
// //     printf("%s\n", ft_memmove(stringeling, teststring2, 5));
// 	char src[] = "lorem ipsum dolor sit amet";
// 	char *dest;
// 	dest = src+1;
//     printf("%s\n", memmove(dest, src, 8));
//     printf("%s\n", ft_memmove(dest, src, 8));
// }
