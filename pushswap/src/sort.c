/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:24:41 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/11 20:47:25 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **stacka, t_node **stackb, t_list **ops)
{
	index_list(stacka);
	position(stacka);
	if (ft_lstsize_ps(*stacka) < 4)
		three_stack(stacka, ops);
	else
		big_stack(stacka, stackb, ops);
}

int	already_sorted(t_node **lst)
{
	t_node	*tmp;
	t_node	*tmpn;
	int		len;

	len = ft_lstsize_ps(*lst);
	if (len < 2)
		return (1);
	tmp = *lst;
	tmpn = (*lst)->next;
	while (len - 1)
	{
		if (tmpn->content < tmp->content)
			return (0);
		tmpn = tmpn->next;
		tmp = tmp->next;
		len--;
	}
	return (1);
}

void	position(t_node **lst)
{
	t_node	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		i++;
		tmp = tmp->next;
	}
}

void	index_list(t_node **stacka)
{
	t_node	*tmpn;
	t_node	*max;
	int		index;

	index = ft_lstsize_ps(*stacka) - 1;
	while (index >= 0)
	{
		tmpn = *stacka;
		max = tmpn;
		while (tmpn)
		{
			if (max->index != 0 || (max->content < tmpn->content
					&& tmpn->index == 0))
				max = tmpn;
			tmpn = tmpn->next;
		}
		max->index = index;
		index--;
	}
}
