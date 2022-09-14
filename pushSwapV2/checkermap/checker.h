/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:03:52 by bde-meij          #+#    #+#             */
/*   Updated: 2022/07/29 12:34:35 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "nextline/get_next_line.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

int			do_and_check_commands(t_list **stack_a, t_list **stack_b);
int			choose_command(t_list **stack_a, t_list **stack_b, char *command);
int			ift_strncmp_bonus(const char *s1, const char *s2, int n);
int			inspect_bonus(int argc, char **argv);
int			ift_strlen_bonus(const char *string);
long int	ft_atoli_bonus(const char *str);

#endif