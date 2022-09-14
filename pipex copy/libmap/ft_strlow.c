/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:42:34 by bde-meij          #+#    #+#             */
/*   Updated: 2022/09/09 11:52:33 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlow(char *str, size_t len)
{
	char	*str2;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (len > ft_strlen(str) || (len < 1))
		return (NULL);
	str2 = malloc(sizeof(char) * ft_strlen(str));
	while (i < len)
	{
		if ((str[i] > 64) && (str[i] < 91))
			str2[i] = str[i] + 32;
		i++;
	}
	return (str2);
}

// int main()
// {
// 	printf("%s\n", strlow("AAAAA", 5));
// 	printf("%s\n", strlow(NULL, 5));
// 	printf("%s\n", strlow("AAAAA", -5));
// 	printf("%s\n", strlow("", 5));
// 	printf("%s\n", strlow(0, 5));
// 	printf("%s\n", strlow("wefvybqioaAOUYuyvouhlL43T24", 360));
// 	printf("%s\n", strlow("IOHBOIYOohybedfalwOIYVER", 5));
// }