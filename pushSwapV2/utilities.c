/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:47:01 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/29 14:35:49 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ift_strlen(const char *string)
{
	int	len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}

long int	ft_atoli(const char *str)
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

void	free_all(t_vars allvars, int list_size)
{
	t_stack	*free_me;

	while (list_size > 0)
	{
		free_me = *allvars.stack_a;
		*allvars.stack_a = (*allvars.stack_a)->next;
		free(free_me);
		list_size--;
	}
	free(allvars.stack_b);
	free(allvars.stack_a);
}
