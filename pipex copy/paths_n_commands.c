/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_n_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:20:03 by bde-meij          #+#    #+#             */
/*   Updated: 2022/09/12 11:12:28 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**paths_strjoin(char **paths, char *command)
{
	char	*free_me;
	int		i;

	i = 0;
	while (paths[i])
	{
		free_me = paths[i];
		paths[i] = protec(ft_strjoin(paths[i], "/"));
		free(free_me);
		free_me = paths[i];
		paths[i] = protec(ft_strjoin(paths[i], command));
		free(free_me);
		i++;
	}
	return (paths);
}

int	validate_string(char **paths)
{
	int	i;

	i = 0;
	while (access(paths[i], X_OK) != 0)
	{
		if (!paths[i])
			break ;
		i++;
	}
	return (i);
}

char	*make_paths(char *pad, char **env, int *exit_value)
{
	char	**paths;
	int		i;

	paths = NULL;
	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	paths = protec(ft_split(&env[i][5], ':'));
	paths = protec(paths_strjoin(paths, pad));
	i = validate_string(paths);
	if (!paths[i])
	{
		error_messages(127);
		*exit_value = 125;
	}
	else
	{
		*exit_value = 0;
		pad = protec(ft_strdup(paths[i]));
	}
	free_paths(paths);
	return (pad);
}

char	**cut_args(char *av)
{
	char	**command;

	command = protec(ft_split(av, ' '));
	if (!*command)
		command[0] = protec(ft_strdup("blah"));
	return (command);
}

void	paths_n_commands(t_var_struct *vars, int ac, char **av, char **env)
{
	int	i;

	i = 0;
	while (i < ac - vars->nonargs)
	{
		vars->commands[i] = protec(cut_args(av[i + (vars->nonargs - 1)]));
		vars->paths[i] = protec(make_paths((vars->commands)[i][0], env, \
		&(vars->exit_value)));
		i++;
	}
}
