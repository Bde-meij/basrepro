/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:29 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:30 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		secondex;
	char	*newstr;

	index = 0;
	secondex = 0;
	newstr = malloc(sizeof(*newstr) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1[index])
	{
		newstr[index] = s1[index];
		index++;
	}
	while (s2[secondex])
	{
		newstr[index + secondex] = s2[secondex];
		secondex++;
	}
	newstr[index + secondex] = '\0';
	return (newstr);
}

// int main()
// {
//     //char strong[] = "jelijpe";
//     //char strung[] = "Islijp";
// 	char	s1[] = "lorem ipsum";
// 	char	s2[] = "dolor sit amet";
// 	s2[1] = '\0';
//     printf("%s", ft_strjoin(s1, s2));
// }
