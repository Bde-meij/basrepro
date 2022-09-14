/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:03:56 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/29 13:36:41 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_and_check_commands(t_list **stack_a, t_list **stack_b)
{
	char	*command;
	int		i;

	command = "\0";
	i = 0;
	while (command != NULL)
	{
		command = get_next_line(0);
		if (command)
			i += choose_command(stack_a, stack_b, command);
		free(command);
	}
	return (i);
}

int	not_sorted(t_list **stack_a, int stack_size)
{
	t_list	*start;
	int		one_if_sorted;

	start = *stack_a;
	one_if_sorted = 1;
	while (stack_size > 1)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			one_if_sorted = 0;
		*stack_a = (*stack_a)->next;
		stack_size--;
	}
	*stack_a = start;
	return (one_if_sorted);
}

void	free_the_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*free_me;

	while (argc > 0)
	{
		free_me = *stack_a;
		*stack_a = (*stack_a)->next;
		free(free_me);
		argc--;
	}
	free(stack_b);
	free(stack_a);
}

int	assign_lists(t_list **stack_a, t_list **stack_b, int stack_size, char **av)
{
	int		list_size;
	t_list	*temp;

	list_size = 0;
	temp = NULL;
	while (list_size < stack_size)
	{
		*stack_a = malloc(sizeof(t_list));
		if (!*stack_a)
		{
			*stack_a = temp;
			free_the_stack(stack_a, stack_b, list_size);
			return (0);
		}
		(*stack_a)->content = ft_atoli_bonus(av[stack_size - list_size]);
		(*stack_a)->next = temp;
		temp = *stack_a;
		list_size++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		**stack_a;
	t_list		**stack_b;

	argc--;
	stack_a = malloc(sizeof(t_list *));
	stack_b = ft_calloc(sizeof(t_list *), 1);
	if ((!stack_a) || (!stack_b))
	{
		free(stack_a);
		free(stack_b);
		return (write(2, "Error\n", 6), 0);
	}
	if (inspect_bonus(argc, argv) > 0)
		return (write(2, "Error\n", 6), 0);
	if (assign_lists(stack_a, stack_b, argc, argv) == 1)
		if (do_and_check_commands(stack_a, stack_b) > 0)
			return (write(2, "Error\n", 6), 0);
	if ((not_sorted(stack_a, argc) == 1) && (!*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
