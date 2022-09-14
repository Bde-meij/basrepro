/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:30 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:31 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dstlen;
	size_t	srclen;

	index = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstlen > dstsize)
		return (srclen + dstsize);
	while (src[index] && ((dstlen + index) < dstsize - 1))
	{
		dst[dstlen + index] = src[index];
		index++;
	}
	dst[dstlen + index] = '\0';
	return (dstlen + srclen);
}

// int main(void)
// {
//     char dst3[40] = "Tokiodorifto";
//     char dst4[40] = "Tokiodorifto";
//     char src2[] = "12345";
//     size_t dstsize2;
//     dstsize2 = 34;

//     printf("\n real strlcat  %zu \n string: %s\n",
// 		strlcat(dst3, src2, dstsize2), dst3);

//     printf("\nmimic strlcat  %zu \n string: %s\n",
// 		ft_strlcat(dst4, src2, dstsize2), dst4);

//     return(0);
// }
