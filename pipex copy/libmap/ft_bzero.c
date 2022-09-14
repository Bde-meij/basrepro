/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:40 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:41 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			index;
	unsigned char	*string;

	string = s;
	index = 0;
	while (index < n)
	{
		string[index] = 0;
		index++;
	}
}

// int main(int argc, char **argv)
// {
//     argv++;
// 	char str[5] = "ABC";
//     ft_bzero(str, 1);
// 	printf("%d",str[2]);
//     // printf("%s", bzero(*argv, 5));
//     //printf("%s", ft_bzero(*argv, 5));
// }
