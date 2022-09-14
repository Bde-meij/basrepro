/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:10:24 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/28 16:50:31 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *stack_a)
{
	int	one;
	int	two;
	int	ione;
	int	itwo;

	one = stack_a->intput;
	two = stack_a->next->intput;
	ione = stack_a->inputindex;
	itwo = stack_a->next->inputindex;
	stack_a->next->intput = one;
	stack_a->intput = two;
	stack_a->next->inputindex = ione;
	stack_a->inputindex = itwo;
}

void	rotate(t_stack *stack_a)
{
	int	intput;
	int	inputindex;

	intput = stack_a->intput;
	inputindex = stack_a->inputindex;
	while (stack_a->next != NULL)
	{
		stack_a->intput = stack_a->next->intput;
		stack_a->inputindex = stack_a->next->inputindex;
		stack_a = stack_a->next;
	}
	stack_a->intput = intput;
	stack_a->inputindex = inputindex;
}

void	rev_rotate(t_stack **stack_a)
{
	t_stack	*start;

	start = (*stack_a);
	while ((*stack_a)->next->next != NULL)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next->next = start;
	start = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = start;
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmptwee;

	tmp = *stack_a;
	tmptwee = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = tmp;
	*stack_a = tmptwee;
}
