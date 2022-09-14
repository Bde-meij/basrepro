/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:19 by bde-meij          #+#    #+#             */
/*   Updated: 2022/09/05 14:52:57 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	unsigned int	index;
	unsigned int	wc;

	if (!s[0])
		return (0);
	index = 1;
	wc = 1;
	if (s[0] == c)
		wc = 0;
	while (s[index] == c)
		index++;
	while (s[index])
	{
		if ((s[index - 1] == c) && (s[index] != c))
			wc++;
		index++;
	}
	return (wc);
}

static int	findstart(char const *s, char c, int wcval)
{
	int	start;

	start = 0;
	wcval++;
	if (s[0] == c)
		wcval++;
	while (wcval > 0)
	{
		while ((s[start] != c) && (wcval != 1))
			start++;
		while (s[start] == c)
			start++;
		wcval--;
	}
	return (start);
}

static int	findlen(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while ((s[start + len] != c) && s[start + len])
		len++;
	return (len);
}

static void	freethings(char ***darray, int wcval)
{
	while ((*darray)[wcval])
	{
		free((*darray)[wcval]);
		(*darray)[wcval] = NULL;
		wcval++;
	}
	free(*darray);
	*darray = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		wcval;
	char	**darray;
	int		start;

	wcval = (wordcount(s, c) - 1);
	darray = malloc(sizeof(char *) * (wcval + 2));
	if (!darray)
		return (NULL);
	darray[wcval + 1] = 0;
	while (wcval >= 0)
	{
		start = findstart(s, c, wcval);
		darray[wcval] = ft_substr(s, start, findlen(s, c, start));
		if (!darray[wcval])
		{
			freethings(&darray, wcval + 1);
			return (NULL);
		}
		wcval--;
	}
	return (darray);
}

// #include <stdio.h>
// int main()
// {
// 	int a = 0;
// 	char s[] = "qwertqwrqeqwtqewrqewtqert";
// 	char c = 't';
// 	char **al;

// 	al = ft_split(s, c);
// 	while (al[a])
// 	{
// 		printf("%s\n", al[a]);
// 		a++;
// 	}
// 	system("leaks -q a.out");
// }
