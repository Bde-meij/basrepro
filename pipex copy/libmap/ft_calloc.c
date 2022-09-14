/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:39 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:40 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	index;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	index = count * size;
	while (index)
	{
		index--;
		ptr[index] = '\0';
	}
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
//     char    *str1;
//     char    *str2;
//     char    *str3;
//     str1 = malloc(20 * sizeof(char));
//     str2 = calloc(20, sizeof(char));
//     str3 = ft_calloc(20, sizeof(char));
//     printf("malloc = %s\n", str1);
//     printf("calloc = %s\n", str2);
//     printf("ft_calloc = %s\n", str3);
// }
