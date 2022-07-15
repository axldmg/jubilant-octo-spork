/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:27:39 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/12 12:47:22 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_list	**lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	display_lst(t_node	**lst)
{
	t_node	*tmp;
	int		i;

	tmp = *lst;
	i = ft_lstsize_ps(tmp);
	while (i > 0)
	{
		ft_printf("This number is: %i\n", tmp->content);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		i--;
	}
}

void	release(t_node **lst)
{
	ft_lstclear_ps(lst);
}

int	compliance_arguments(char *s)
{
	int	len;
	int	i;

	if (!*s)
		return (0);
	if (!ft_secure_atoi(s))
		return (0);
	len = ft_strlen(s);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if ((s[i] == '-' || s[i] == '+') && ft_strlen(s) > 1)
			i++;
	while (i < len)
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	compliance_duplicates(t_node **lst)
{
	t_node	*tmp;
	t_node	*tmpn;
	int		hit;

	tmp = *lst;
	hit = 0;
	while (tmp->next)
	{
		tmpn = tmp->next;
		while (tmpn->next)
		{
			if (tmpn->content == tmp->content)
				hit++;
			tmpn = tmpn->next;
		}
		if (tmpn->content == tmp->content)
			hit++;
		if (hit)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
