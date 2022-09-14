/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:37 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:38 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	retval;
	size_t	index;

	retval = 0;
	index = 0;
	while ((index < n) && (s1[index] || s2[index]))
	{
		retval = ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
		if (retval != 0)
			return (retval);
	}
	return (retval);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char s1[] = "b\200";
//     char s2[] = "a\0";
//     printf("%d\n", ft_strncmp(s1, s2, 2));
//     printf("%d", strncmp(s1, s2, 2));
// }
