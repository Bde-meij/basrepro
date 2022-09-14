/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:43:50 by bde-meij          #+#    #+#             */
/*   Updated: 2022/09/12 15:45:34 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <fcntl.h>
# include "libmap/libft.h"
# include "nextline/get_next_line.h"

typedef struct a_struct
{
	char	**paths;
	char	***commands;
	char	*infile;
	char	*outfile;
	int		argc;
	int		nonargs;
	int		exit_value;
}	t_var_struct;

//paths_n_commands
void	paths_n_commands(t_var_struct *vars, int ac, char **av, char **env);
char	*make_paths(char *pad, char **env, int *exit_value);
char	**paths_strjoin(char **paths, char *command);
int		validate_string(char **paths);
char	**cut_args(char *av);

//protect_n_free
void	error_messages(int error_code);
void	free_paths(char **paths);
int		guard_fd_fork(int i);
void	*protec(void *ptr);

//bonus_section
void	determine_infile(t_var_struct *vars, char **av);
void	command_loop(t_var_struct vars, int i);
char	*make_heredoc(char *delimiter);

#endif