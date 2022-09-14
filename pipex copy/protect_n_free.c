/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_n_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:36:39 by bde-meij          #+#    #+#             */
/*   Updated: 2022/09/12 11:22:31 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_messages(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd("Error\n", 2);
	if (error_code == 2)
		ft_putstr_fd("Misuse of shell builtins\n", 2);
	if (error_code == 127)
		ft_putstr_fd("Command not found\n", 2);
	if (error_code == -1)
		ft_putstr_fd("Input file does not exist\n", 2);
	if (error_code == -2)
		ft_putstr_fd("Malloc fail\n", 2);
	if (error_code == -3)
		ft_putstr_fd("Pipe or FD fail\n", 2);
	if (error_code == -4)
		ft_putstr_fd("Incorrect number of args\n", 2);
}

void	*protec(void *ptr)
{
	if (ptr == NULL)
	{
		error_messages(-2);
		exit(1);
	}
	return (ptr);
}

int	guard_fd_fork(int i)
{
	if (i == -1)
	{
		error_messages(-3);
		exit(1);
	}
	return (i);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	paths = NULL;
}
