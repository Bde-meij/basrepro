/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 09:25:58 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/29 12:44:50 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	alldigits(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while ((argv[i] >= '0') && (argv[i] <= '9'))
		i++;
	if (i != ift_strlen_bonus(argv))
		return (1);
	return (0);
}

int	validate_values(char **argv)
{
	long int	min;
	long int	max;
	int			i;

	min = -2147483649;
	max = 2147483648;
	i = 1;
	while (argv[i])
	{
		if ((alldigits(argv[i]) == 1) || \
			((ft_atoli_bonus(argv[i]) <= min) || \
				(ft_atoli_bonus(argv[i]) >= max)))
			return (1);
		i++;
	}
	return (0);
}

int	seek_doubles(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoli_bonus(argv[i]) == \
				ft_atoli_bonus(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	inspect_bonus(int argc, char **argv)
{
	int	o_for_succes;

	o_for_succes = 0;
	o_for_succes += validate_values(argv);
	if (argc > 1)
		o_for_succes += seek_doubles(argv);
	return (o_for_succes);
}
