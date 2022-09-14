/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:10:21 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/01 11:22:17 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_stack **stack_a, int high)
{
	if (high > 2)
	{
		if ((*stack_a)->inputindex == high)
		{
			rotate(*stack_a);
			write(1, "ra\n", 3);
		}
		if ((*stack_a)->next->inputindex == high)
		{
			rev_rotate(stack_a);
			write(1, "rra\n", 4);
		}
	}
	if ((*stack_a)->intput > (*stack_a)->next->intput)
	{
		swap(*stack_a);
		write(1, "sa\n", 3);
	}
}

void	rotate_to_high_or_low(t_stack *stack_a, int low, int high)
{
	while (stack_a->inputindex != high && stack_a->inputindex != low)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	if ((*stack_a)->inputindex > (*stack_a)->next->inputindex)
	{
		rotate(*stack_a);
		write(1, "ra\n", 3);
	}
}

void	sort_ten(t_stack **stack_a, t_stack **stack_b, int low, int high)
{
	if ((high - low) <= 2)
		sort_three(stack_a, high);
	else
	{
		rotate_to_high_or_low(*stack_a, low, high);
		if ((*stack_a)->inputindex == high)
			high--;
		else
			low++;
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
		sort_ten(stack_a, stack_b, low, high);
		push_back(stack_a, stack_b);
	}
}

void	initiate_hardsort(t_vars allvars)
{
	int	low;
	int	high;

	low = 1;
	high = allvars.stack_size;
	sort_ten(allvars.stack_a, allvars.stack_b, low, high);
}
