/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:40 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:41 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*str;

	index = 0;
	str = (char *) s;
	while (s[index])
		index++;
	while (index > -1)
	{
		if (s[index] == (char) c)
			return (str + index);
		index--;
	}
	return (0);
}

// int main()
// {
//     char str[] = "klaas";
//     printf("%s", ft_strrchr(str, 'h'));
//     printf("%s", strrchr(str, 'h'));
// }
