/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:43:26 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/29 15:39:16 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	assign_lists(t_vars allvars)
{
	t_stack	*temp;
	int		list_size;

	list_size = 0;
	temp = NULL;
	while (list_size < allvars.stack_size)
	{
		*(allvars.stack_a) = malloc(sizeof(t_stack *));
		if (!*(allvars.stack_a))
		{
			*(allvars.stack_a) = temp;
			free_all(allvars, list_size);
			return (0);
		}								
		(*(allvars.stack_a))->intput = \
		ft_atoli(allvars.arguments[allvars.stack_size - list_size]);
		(*(allvars.stack_a))->inputindex = -1;
		(*(allvars.stack_a))->next = temp;
		temp = *(allvars.stack_a);
		list_size++;
	}
	return (1);
}

void	index_lists(t_vars allvars)
{
	t_stack		*start;
	int			loopsize;
	int			indexvalue;

	start = *(allvars.stack_a);
	indexvalue = 1;
	while (indexvalue <= allvars.stack_size)
	{
		loopsize = allvars.stack_size;
		while (loopsize > 0)
		{
			if ((allvars.max > (*(allvars.stack_a))->intput) && \
				(allvars.min < (*(allvars.stack_a))->intput))
			{
				allvars.max = (*(allvars.stack_a))->intput;
				(*(allvars.stack_a))->inputindex = indexvalue;
			}
			*(allvars.stack_a) = (*(allvars.stack_a))->next;
			loopsize--;
		}
		allvars.min = allvars.max;
		allvars.max = 2147483648;
		*(allvars.stack_a) = start;
		indexvalue++;
	}
}

int	not_sorted(t_vars allvars)
{
	t_stack	*start;
	int		one_if_sorted;

	start = *(allvars.stack_a);
	one_if_sorted = 1;
	while (allvars.stack_size > 1)
	{
		if ((*(allvars.stack_a))->intput > (*(allvars.stack_a))->next->intput)
			one_if_sorted = 0;
		*(allvars.stack_a) = (*(allvars.stack_a))->next;
		allvars.stack_size--;
	}
	*(allvars.stack_a) = start;
	return (one_if_sorted);
}

void	radix(t_vars allvars, int binary)
{
	int	b_size;

	b_size = 0;
	while (allvars.stack_size > 0)
	{
		if (((*(allvars.stack_a))->inputindex & (binary)) == 0)
		{
			push(allvars.stack_a, allvars.stack_b);
			b_size++;
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(*(allvars.stack_a));
			write(1, "ra\n", 3);
		}
		allvars.stack_size--;
	}
	while (b_size > 0)
	{
		push(allvars.stack_b, allvars.stack_a);
		write(1, "pa\n", 3);
		b_size--;
	}
}
