/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:42 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:48:43 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	untrimmedsize;
	size_t	start;

	untrimmedsize = 0;
	start = 0;
	while (start < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[start]) == 0)
			break ;
		start++;
	}
	while (untrimmedsize < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[ft_strlen(s1) - untrimmedsize]) == 0)
			break ;
		untrimmedsize++;
	}
	untrimmedsize--;
	trim = ft_substr(s1, start, (ft_strlen(s1) - untrimmedsize - start));
	return (trim);
}

// int main()
// {
//char s1[] = "";
//char s2[] = "iis";
// char s3[] = "abffffab";
// char s4[] = "ab";
// printf("%s\n", ft_strtrim(s3, s4));
// printf("%s\n", ft_strtrim(s2, s1));
// printf("%s\n", ft_strtrim(s1, s2));
// printf("%s\n", ft_strtrim(s2, s1));
//}
