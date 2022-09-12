/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:12:59 by bschoeff          #+#    #+#             */
/*   Updated: 2022/09/06 09:48:01 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipx;
	int		i;
	int		flag;
	t_fds	*fds;

	pipx = NULL;
	fds = NULL;
	if (ac != 5)
		return (ft_putstr_fd("Wrong usage of ./pipex\n", 2), 1);
	i = 0;
	while (++i < ac)
	{
		flag = 1;
		if (i == 1 || i == ac - 1)
			flag = 0;
		if (!populate(&pipx, av[i], flag, envp))
			return (clean_pipx(&pipx, (*del)), 1);
	}
	assign_order(&pipx, ac);
	if (!check_compliance(&pipx) || !instantiate_fds(&pipx, &fds)
		|| !execute(&pipx, &fds))
		return (clean_pipx(&pipx, (*del)), clean_fds(&fds), 2);
	return (clean_pipx(&pipx, (*del)), clean_fds(&fds), 0);
}

int	instantiate_fds(t_pipex **pipx, t_fds **fds)
{
	t_pipex	*tmp;

	*fds = malloc(sizeof(t_fds));
	if (!*fds)
		return (0);
	tmp = *pipx;
	while (tmp)
	{
		tmp->fds = *fds;
		tmp = tmp->next;
	}
	tmp = *pipx;
	while (tmp)
	{
		if (tmp->pathfile && !tmp->position)
			(*fds)->in_fd = open(tmp->pathfile, O_RDONLY);
		if (tmp->pathfile && tmp->position == tmp->end)
			(*fds)->out_fd = open(tmp->pathfile, O_WRONLY);
		tmp = tmp->next;
	}
	return (1);
}

void	assign_order(t_pipex **pipx, int ac)
{
	t_pipex	*tmp;
	int		i;

	i = 0;
	tmp = (*pipx);
	while (tmp)
	{
		tmp->position = i;
		tmp->end = ac - 2;
		tmp = tmp->next;
		i++;
	}
}
