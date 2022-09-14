/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:11 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:12 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*string;

	string = b;
	index = 0;
	while (index < len)
	{
		string[index] = (unsigned char)c;
		index++;
	}
	return (string);
}

// int main(int argc, char **argv)
// {
//     argv++;
//     printf("%s", ft_memset(*argv, '0', 2));
//     printf("%s", memset(*argv, '0', 2));
// }
