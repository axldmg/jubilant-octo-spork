/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:20:24 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/12 11:57:00 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sanitize(t_list **ops)
{
	sanitize_rotate(ops);
	sanitize_rev_rotate(ops);
}

void	sanitize_rotate(t_list	**ops)
{
	t_list	*tmp;
	t_list	*tmpn;

	tmp = *ops;
	while (tmp->next)
	{
		tmpn = tmp->next;
		if ((!ft_strcmp(tmp->content, "ra") && !ft_strcmp(tmpn->content, "rb"))
			|| (!ft_strcmp(tmp->content, "rb")
				&& !ft_strcmp(tmpn->content, "ra")))
		{
			tmp->content = "rr";
			tmp->next = tmpn->next;
			free(tmpn);
		}
		tmp = tmp->next;
	}
}

void	sanitize_rev_rotate(t_list **ops)
{
	t_list	*tmp;
	t_list	*tmpn;

	tmp = *ops;
	while (tmp->next)
	{
		tmpn = tmp->next;
		if ((!ft_strcmp(tmp->content, "rra")
				&& !ft_strcmp(tmpn->content, "rrb"))
			|| (!ft_strcmp(tmp->content, "rrb")
				&& !ft_strcmp(tmpn->content, "rra")))
		{
			tmp->content = "rrr";
			tmp->next = tmpn->next;
			free(tmpn);
		}
		tmp = tmp->next;
	}
}
