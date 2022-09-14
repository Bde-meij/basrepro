/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:03:43 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/29 12:34:13 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	s(t_list *stack_a)
{
	int	one;
	int	two;

	one = stack_a->content;
	two = stack_a->next->content;
	stack_a->next->content = one;
	stack_a->content = two;
}

void	r(t_list *stack_a)
{
	int	content;

	content = stack_a->content;
	while (stack_a->next != NULL)
	{
		stack_a->content = stack_a->next->content;
		stack_a = stack_a->next;
	}
	stack_a->content = content;
}

void	rr(t_list **stack_a)
{
	t_list	*start;

	start = (*stack_a);
	while ((*stack_a)->next->next != NULL)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next->next = start;
	start = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = start;
}

void	p(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmptwee;

	tmp = *stack_a;
	tmptwee = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = tmp;
	*stack_a = tmptwee;
}

int	choose_command(t_list **stack_a, t_list **stack_b, char *command)
{
	if (ift_strncmp_bonus(command, "sa\n", 4) == 0)
		s(*stack_a);
	else if (ift_strncmp_bonus(command, "sb\n", 4) == 0)
		s(*stack_b);
	else if (ift_strncmp_bonus(command, "ra\n", 4) == 0)
		r(*stack_a);
	else if (ift_strncmp_bonus(command, "rb\n", 4) == 0)
		r(*stack_b);
	else if (ift_strncmp_bonus(command, "rra\n", 4) == 0)
		rr(stack_a);
	else if (ift_strncmp_bonus(command, "rrb\n", 4) == 0)
		rr(stack_b);
	else if (ift_strncmp_bonus(command, "pb\n", 4) == 0)
		p(stack_a, stack_b);
	else if (ift_strncmp_bonus(command, "pa\n", 4) == 0)
		p(stack_b, stack_a);
	else
		return (1);
	return (0);
}
