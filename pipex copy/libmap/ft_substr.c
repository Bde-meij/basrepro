/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:44 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:45 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(*sub) * (len + 1));
	if (!sub)
		return (NULL);
	while ((i < len) && (s[start] != '\0') && ((start + i) <= ft_strlen(s)))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// #include <stdio.h>
// int main()
// {
// char stringkampioen[] = "eentweedri   eviervijfzes";
// printf("%s", ft_substr(stringkampioen, 0, 20));
// 	char *dst1 = ft_substr("hello", 10, 4);
// 	printf("|%s|\n",  dst1);
// }
// if ((start > ft_strlen(s))) //|| (len <= 0))
// 	return (NULL);
