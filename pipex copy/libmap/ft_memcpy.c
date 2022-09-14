/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:14 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:15 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*dststr;
	char	*srcstr;

	dststr = (char *) dst;
	srcstr = (char *) src;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	index = 0;
	while (index < n)
	{
		dststr[index] = srcstr[index];
		index++;
	}
	return (dststr);
}

// int main()
// {
//     char stringeling[] = "ikbeneenstring";
//     char garechar[] = "waarismijnstring";
//     printf("%s\n", memcpy(stringeling, garechar, 6));
//     printf("%s\n", ft_memcpy(stringeling, garechar, 6));
// }
