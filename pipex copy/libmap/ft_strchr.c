/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:22 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:23 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*str;

	index = 0;
	str = (char *) s;
	while (str[index])
	{
		if (str[index] == (char) c)
			return (str + index);
		index++;
	}
	if (c == '\0')
		return (str + index);
	return (NULL);
}

// int main()
// {
//     char str[] = "klaas";
//     printf("%s", ft_strchr(str, a));
//     printf("%s", strchr(str, '\0'));
// }
// int main()
// {
//     char str[] = "truipouille";
//     printf("%s\n", ft_strchr(str, 't' + 1));
//     printf("%s", strchr(str, 't' + 1));
// }
