/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:10:15 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/29 15:49:49 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				intput;
	int				inputindex;
	struct s_list	*next;
}	t_stack;

typedef struct a_struct
{
	t_stack		**stack_a;
	t_stack		**stack_b;
	char		**arguments;
	int			stack_size;
	long int	min;
	long int	max;
}	t_vars;

void		free_all(t_vars allvars, int list_size);
int			ift_strlen(const char *string);
long int	ft_atoli(const char *str);
int			inspect_input(t_vars allvars);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		rev_rotate(t_stack **stack);
void		push(t_stack **stack_one, t_stack **stack_two);
void		initiate_hardsort(t_vars allvars);
int			assign_lists(t_vars allvars);
void		index_lists(t_vars allvars);
int			not_sorted(t_vars allvars);
void		radix(t_vars allvars, int binary);

#endif