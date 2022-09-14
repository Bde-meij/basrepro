/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:33 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:34 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len])
	{
		len++;
	}
	return (len);
}

// int main(int argc, char **argv)
// {
//     (void) argc;
//     argv++;
//     printf("%lu \n", ft_strlen(*argv));
//     printf("%lu", strlen(*argv));
// }
