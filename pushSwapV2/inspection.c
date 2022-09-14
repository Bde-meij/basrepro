/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 09:25:58 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/01 11:18:00 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	alldigits(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while ((argv[i] >= '0') && (argv[i] <= '9'))
		i++;
	if (i != ift_strlen(argv))
		return (1);
	return (0);
}

int	validate_values(t_vars allvars)
{
	int	i;

	i = 1;
	while (allvars.arguments[i])
	{
		if ((alldigits(allvars.arguments[i]) == 1) || \
			((ft_atoli(allvars.arguments[i]) <= allvars.min) || \
				(ft_atoli(allvars.arguments[i]) >= allvars.max)))
			return (1);
		i++;
	}
	return (0);
}

int	seek_doubles(t_vars allvars)
{
	int	i;
	int	j;

	i = 1;
	while (allvars.arguments[i])
	{
		j = i + 1;
		while (allvars.arguments[j])
		{
			if (ft_atoli(allvars.arguments[i]) == \
				ft_atoli(allvars.arguments[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	inspect_input(t_vars allvars)
{
	int	o_for_succes;

	o_for_succes = 0;
	o_for_succes += validate_values(allvars);
	if (allvars.stack_size > 1)
		o_for_succes += seek_doubles(allvars);
	return (o_for_succes);
}
