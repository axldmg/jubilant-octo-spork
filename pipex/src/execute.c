/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:06:47 by bschoeff          #+#    #+#             */
/*   Updated: 2022/09/06 09:41:59 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute(t_pipex **pipx, t_fds **fds)
{
	t_pipex	*tmp;

	tmp = (*pipx)->next;
	pipe(tmp->fds->pfd);
	tmp->fds->fst_child = fork();
	if (tmp->fds->fst_child == -1)
		return (perror("Fork: "), 0);
	if (!tmp->fds->fst_child)
		exec_first_child(tmp, pipx, fds);
	tmp = tmp->next;
	tmp->fds->snd_child = fork();
	if (tmp->fds->snd_child == -1)
		return (perror("Fork: "), 0);
	if (!tmp->fds->snd_child)
		exec_second_child(tmp, pipx, fds);
	close(tmp->fds->pfd[0]);
	close(tmp->fds->pfd[1]);
	waitpid(tmp->fds->fst_child, &tmp->status, 0);
	waitpid(tmp->fds->snd_child, &tmp->status, 0);
	return (1);
}

void	exec_first_child(t_pipex *tmp, t_pipex **pipx, t_fds **fds)
{
	close(tmp->fds->pfd[0]);
	if (dup2(tmp->fds->in_fd, 0) == -1 || dup2(tmp->fds->pfd[1], 1) == -1)
	{
		perror("Dup ");
		clean_pipx(pipx, (*del));
		clean_fds(fds);
		exit (0);
	}
	if (!tmp->pathcmd)
	{
		clean_pipx(pipx, (*del));
		clean_fds(fds);
		exit(0);
	}
	execve(tmp->pathcmd, tmp->cmd, 0);
	clean_pipx(pipx, (*del));
	clean_fds(fds);
}

void	exec_second_child(t_pipex *tmp, t_pipex **pipx, t_fds **fds)
{
	close(tmp->fds->pfd[1]);
	if (dup2(tmp->fds->pfd[0], 0) == -1 || dup2(tmp->fds->out_fd, 1) == -1)
	{
		perror("Dup ");
		clean_pipx(pipx, (*del));
		clean_fds(fds);
		exit (0);
	}
	if (!tmp->pathcmd)
	{
		clean_pipx(pipx, (*del));
		clean_fds(fds);
		exit(0);
	}
	execve(tmp->pathcmd, tmp->cmd, 0);
	clean_pipx(pipx, (*del));
	clean_fds(fds);
}
