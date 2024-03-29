/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:35:34 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/27 11:43:38 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	index;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	index = count * size;
	while (index)
	{
		index--;
		ptr[index] = '\0';
	}
	return (ptr);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	i = 0;
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
