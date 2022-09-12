/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:30:08 by bschoeff          #+#    #+#             */
/*   Updated: 2022/08/31 08:55:53 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	add_back(t_pipex **pipx, t_pipex *new)
{
	t_pipex	*tmp;

	if (!(*pipx))
	{
		(*pipx) = new;
		return ;
	}
	tmp = (*pipx);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_len(s1) + ft_len(s2) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '/';
	i++;
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_cpy(t_pipex *new, char *str)
{
	int	i;

	new->pathcmd = malloc(ft_len(str) + 1);
	if (!new->pathcmd)
		return ;
	i = -1;
	while (str[++i])
		new->pathcmd[i] = str[i];
	new->pathcmd[i] = '\0';
}
