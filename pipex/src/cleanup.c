/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:53:47 by bschoeff          #+#    #+#             */
/*   Updated: 2022/09/06 09:25:25 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_pipx(t_pipex **pipx, void (*del)(char **))
{
	t_pipex	*tmp;

	while ((*pipx))
	{
		tmp = (*pipx);
		(*pipx) = (*pipx)->next;
		if (tmp->ev_path)
			del(tmp->ev_path);
		if (tmp->cmd)
			del(tmp->cmd);
		if (tmp->pathcmd)
			free(tmp->pathcmd);
		free(tmp);
	}
}

void	del(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	clean_fds(t_fds **fds)
{
	if (!(*fds))
		return ;
	close((*fds)->in_fd);
	close((*fds)->out_fd);
	free(*fds);
}
