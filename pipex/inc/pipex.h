/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:11:43 by bschoeff          #+#    #+#             */
/*   Updated: 2022/09/06 09:43:33 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

typedef struct s_fds
{
	int			pfd[2];
	int			in_fd;
	int			out_fd;
	pid_t		fst_child;
	pid_t		snd_child;
}			t_fds;

typedef struct s_pipex
{
	char			*pathfile;
	char			*pathcmd;
	char			**cmd;
	char			**ev_path;
	int				position;
	int				end;
	int				status;
	t_fds			*fds;
	struct s_pipex	*next;
}			t_pipex;

/* Main */
int		instantiate_fds(t_pipex **pipx, t_fds **fds);
void	assign_order(t_pipex **pipx, int ac);

/* Parsing */
int		populate(t_pipex **pipx, char *str, int flag, char **envp);
void	find_path(t_pipex *new, char **envp);
void	initialize_node(t_pipex *new);

/* Parsing utils */
int		check_cmd(t_pipex *new);
void	parse_envp(t_pipex *new, char **envp);
void	sanitize_cmd(t_pipex *new);
void	fill_pathcmd(t_pipex *new);

/* Utils */
void	add_back(t_pipex **pipx, t_pipex *new);
int		ft_len(char *s);
char	*ft_join(char *s1, char *s2);
void	ft_cpy(t_pipex *new, char *str);

/* Execute */
int		execute(t_pipex **pipx, t_fds **fds);
void	exec_first_child(t_pipex *tmp, t_pipex **pipx, t_fds **fds);
void	exec_second_child(t_pipex *tmp, t_pipex **pipx, t_fds **fds);

/* Compliance */
int		env_compliance(int ac, char **av);
int		check_compliance(t_pipex **pipx);
int		compl_first(t_pipex *tmp);
int		compl_last(t_pipex *tmp);
int		search_path(char *s1, char *s2);

/* Cleanup */
void	clean_pipx(t_pipex **pipx, void (*del)(char **));
void	del(char **tab);
void	clean_fds(t_fds **fds);

#endif
