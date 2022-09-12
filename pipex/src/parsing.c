/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:50:12 by bschoeff          #+#    #+#             */
/*   Updated: 2022/09/05 10:39:21 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	populate(t_pipex **pipx, char *str, int flag, char **envp)
{
	t_pipex	*new;

	new = malloc(sizeof(t_pipex));
	if (!new)
		return (0);
	initialize_node(new);
	if (!flag)
		new->pathfile = str;
	else
	{
		if (!str || !*str)
			new->cmd = NULL;
		else
			new->cmd = ft_split_pipex(str, ' ');
		find_path(new, envp);
	}
	add_back(pipx, new);
	return (1);
}

void	find_path(t_pipex *new, char **envp)
{
	parse_envp(new, envp);
	if (!new->cmd)
	{
		ft_printf("Command '' not found\n");
		return ;
	}
	if (check_cmd(new))
	{
		if (!access(new->cmd[0], X_OK))
			ft_cpy(new, new->cmd[0]);
		else
			ft_printf("Error: %s: %s\n", new->cmd[0], strerror(errno));
		sanitize_cmd(new);
	}
	else
	{
		fill_pathcmd(new);
		if (!(*envp))
			ft_printf("bash: %s: No such file or directory\n", new->cmd[0]);
		else if (!new->pathcmd)
			ft_printf("Command '%s' not found\n", new->cmd[0]);
	}
}

void	initialize_node(t_pipex *new)
{
	new->pathfile = NULL;
	new->pathcmd = NULL;
	new->cmd = NULL;
	new->ev_path = NULL;
	new->position = 0;
	new->end = 0;
	new->next = NULL;
}
