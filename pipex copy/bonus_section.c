/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:06:40 by bde-meij          #+#    #+#             */
/*   Updated: 2022/09/09 16:35:41 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*make_heredoc(char *delimiter)
{
	char	*doc;
	int		fd;

	fd = open(".here_doc", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	while (1)
	{
		doc = get_next_line(0);
		if ((ft_strncmp(doc, delimiter, ft_strlen(delimiter)) == 0) && \
			(ft_strlen(delimiter) == ft_strlen(doc) - 1))
			break ;
		write(fd, doc, ft_strlen(doc));
		free(doc);
		doc = NULL;
	}
	free(doc);
	doc = NULL;
	close(fd);
	return (".here_doc");
}

void	determine_infile(t_var_struct *vars, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		vars->infile = make_heredoc(av[2]);
		vars->nonargs = 4;
	}
	else
	{
		vars->infile = av[1];
		vars->nonargs = 3;
	}
}

void	command_loop(t_var_struct vars, int i)
{
	pid_t	sid;
	int		sd[2];

	guard_fd_fork(pipe(sd));
	sid = guard_fd_fork(fork());
	if (sid == 0)
	{
		close(sd[0]);
		dup2(sd[1], 1);
		execve(vars.paths[i], vars.commands[i], NULL);
		exit(2);
	}
	dup2(sd[0], 0);
	close(sd[1]);
}
