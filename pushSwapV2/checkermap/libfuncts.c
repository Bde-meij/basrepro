/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfuncts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:08:45 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/29 12:43:44 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ift_strlen_bonus(const char *string)
{
	int	len;

	len = 0;
	while (string[len])
	{
		len++;
	}
	return (len);
}

int	ift_strncmp_bonus(const char *s1, const char *s2, int n)
{
	int	retval;
	int	index;

	retval = 0;
	index = 0;
	while ((index < n) && (s1[index] || s2[index]))
	{
		retval = ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
		if (retval != 0)
			return (retval);
	}
	return (retval);
}

long int	ft_atoli_bonus(const char *str)
{
	long int	value;
	long int	index;
	long int	sign;

	value = 0;
	index = 0;
	sign = 1;
	while ((str[index] == 32) || (str[index] >= 9 && str[index] <= 13))
		index++;
	if ((str[index] == '-') || (str[index] == '+'))
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while ((str[index] >= '0') && (str[index] <= '9'))
	{
		value *= 10;
		value += (str[index] - 48);
		index++;
	}
	return (value * sign);
}
