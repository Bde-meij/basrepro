/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:25 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:26 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	index;
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	index = 0;
	s2 = malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	while (index < len)
	{
		s2[index] = s1[index];
		index++;
	}
	s2[index] = '\0';
	return (s2);
}

// int main(int argc, char **argv)
// {
// 	(void) argc;
//     argv++;
//     printf("%s\n", ft_strdup(*argv));
//     printf("%s", strdup(*argv));
// }
