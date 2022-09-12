/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:00:26 by bschoeff          #+#    #+#             */
/*   Updated: 2022/08/26 12:12:23 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(t_pipex *new)
{
	int	i;

	if (!new->cmd[0])
		return (1);
	i = -1;
	while (new->cmd[0][++i])
		if (new->cmd[0][i] == '/')
			return (1);
	return (0);
}

void	parse_envp(t_pipex *new, char **envp)
{
	int		i;
	char	*str;

	if (!envp || !*envp)
	{
		new->ev_path = NULL;
		return ;
	}
	i = -1;
	while (envp[++i])
		if (search_path(envp[i], "PATH="))
			break ;
	str = &envp[i][5];
	new->ev_path = ft_split(str, ':');
}

void	sanitize_cmd(t_pipex *new)
{
	char	**tab;
	int		i;
	int		j;

	tab = ft_split(new->cmd[0], '/');
	i = 0;
	while (tab[i])
		i++;
	i--;
	free(new->cmd[0]);
	new->cmd[0] = malloc(ft_strlen(tab[i]) + 1);
	if (!new->cmd[0])
		return ;
	j = -1;
	while (tab[i][++j])
		new->cmd[0][j] = tab[i][j];
	new->cmd[0][j] = '\0';
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	fill_pathcmd(t_pipex *new)
{
	int		i;
	char	*str;

	if (!new->ev_path)
	{
		new->pathcmd = NULL;
		return ;
	}
	i = -1;
	while (new->ev_path[++i])
	{
		str = ft_join(new->ev_path[i], new->cmd[0]);
		if (!access(str, X_OK))
		{
			ft_cpy(new, str);
			free(str);
			return ;
		}
		free(str);
	}
}
