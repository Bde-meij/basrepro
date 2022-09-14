/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:10:29 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 15:19:04 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_logic(t_vars allvars)
{
	int	binary;

	binary = 1;
	index_lists(allvars);
	if ((allvars.stack_size < 11) && (not_sorted(allvars) == 0))
		initiate_hardsort(allvars);
	while (not_sorted(allvars) == 0)
	{
		radix(allvars, binary);
		binary = binary * 2;
	}
}

void	ft_freestacks_a_b(t_vars allvars)
{
	free(allvars.stack_a);
	free(allvars.stack_b);
}

int	inspect_vars(t_vars allvars)
{
	if ((!allvars.stack_a) || (!allvars.stack_b))
		ft_freestacks_a_b(allvars);
	else if (allvars.stack_size == 0)
		return (0);
	else if (inspect_input(allvars) > 0)
		write(2, "Error\n", 6);
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	allvars;

	allvars.min = -2147483649;
	allvars.max = 2147483648;
	allvars.stack_size = ac - 1;
	allvars.arguments = av;
	allvars.stack_a = malloc(sizeof(t_stack *));
	allvars.stack_b = malloc(sizeof(t_stack *));
	if ((inspect_vars(allvars) == 0) || (allvars.stack_size == 1))
		return (0);
	if (assign_lists(allvars) == 1)
	{
		do_logic(allvars);
		free_all(allvars, allvars.stack_size);
	}
	return (0);
}

// system("leaks -q push_swap");
// while (allvars.stack_size > 0)
// {
// 	printf("%d\n", (*allvars.stack_a)->intput);
// 	printf("%d\n", (*allvars.stack_a)->inputindex);
// 	*allvars.stack_a = (*allvars.stack_a)->next;
// 	allvars.stack_size--;
// }