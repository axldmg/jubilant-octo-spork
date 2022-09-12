/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compliance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:50:52 by bschoeff          #+#    #+#             */
/*   Updated: 2022/09/09 15:31:59 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	env_compliance(int ac, char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 2;
	flag = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '/')
				flag = 1;
			j++;
		}
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

int	check_compliance(t_pipex **pipx)
{
	t_pipex	*tmp;

	tmp = *pipx;
	while (tmp)
	{
		if (!tmp->position)
			if (!compl_first(tmp))
				return (0);
		if (tmp->position == tmp->end)
			if (!compl_last(tmp))
				return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	compl_first(t_pipex *tmp)
{
	int		fd;

	fd = open(tmp->pathfile, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: %s %s\n", tmp->pathfile, strerror(errno));
		tmp->pathfile = NULL;
		return (0);
	}
	return (close(fd), 1);
}

int	compl_last(t_pipex *tmp)
{
	int	fd;

	fd = open(tmp->pathfile, O_CREAT, 400, 200);
	if (fd < 0)
	{
		ft_printf("Error: %s %s\n", tmp->pathfile, strerror(errno));
		return (0);
	}
	return (close(fd), 1);
}

int	search_path(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
