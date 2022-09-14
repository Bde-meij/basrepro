/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:20:00 by bde-meij          #+#    #+#             */
/*   Updated: 2022/09/14 12:35:57 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_read_end(t_var_struct vars, int *fd)
{
	int md;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	md = open(vars.infile, 'r');
	dup2(md, 0);
	close(md);
	execve(vars.paths[0], vars.commands[0], NULL);
	exit(2);
}

void	pipe_write_end(t_var_struct vars, int *fd, int i)
{
	close(fd[1]);
	dup2(fd[0], 0);
	if (vars.nonargs == 4)
		dup2(open(vars.outfile, O_WRONLY | O_APPEND | O_CREAT, 0644), 1);
	else
		dup2(open(vars.outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644), 1);
	close(fd[0]);
	while (i < (vars.argc - vars.nonargs))
	{
		command_loop(vars, i);
		i++;
	}
	execve(vars.paths[vars.argc - vars.nonargs], \
		vars.commands[vars.argc - vars.nonargs], NULL);
	exit(2);
}

int	pipex(t_var_struct vars)
{
	pid_t	pid;
	int		fd[2];

	guard_fd_fork(pipe(fd));
	pid = guard_fd_fork(fork());
	if ((pid == 0) && (access(vars.infile, R_OK) != -1))
		pipe_read_end(vars, fd);
	if (pid > 0)
		pipe_write_end(vars, fd, 0);
	exit(2);
}

int	parent_pipe(t_var_struct vars)
{
	pid_t	pid;
	int		wstatus;
	int		return_value;

	wstatus = 0;
	return_value = 0;
	pid = guard_fd_fork(fork());
	if (pid == 0)
	{
		pipex(vars);
		exit(2);
	}
	else
	{
		if (waitpid(pid, &wstatus, 0) > 0)
			if (WIFEXITED(wstatus))
				return_value = WEXITSTATUS(wstatus);
	}
	return (return_value);
}

int	main(int ac, char **av, char **env)
{
	t_var_struct	vars;

	vars.exit_value = 0;
	vars.argc = ac - 1;
	if (ac < 5)
		return (error_messages(-4), 1);
	determine_infile(&vars, av);
	error_messages(access(vars.infile, R_OK));
	vars.paths = protec(malloc(sizeof(char *) * (ac - vars.nonargs)));
	vars.commands = protec(malloc(sizeof(char *) * (ac - vars.nonargs)));
	vars.outfile = av[vars.argc];
	paths_n_commands(&vars, ac, av, env);
	vars.exit_value += parent_pipe(vars);
	unlink(".here_doc");
	if (vars.exit_value != 127)
		error_messages(vars.exit_value);
	return (vars.exit_value);
}
