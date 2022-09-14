/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:35 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:36 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 0177)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(int argc, char **argv)
// {
//     printf("%d", ft_isascii(*argv[1]));
//     printf("%d", isascii(*argv[1]));
// }
