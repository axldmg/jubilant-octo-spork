/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:16:07 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/11 20:27:29 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_stack(t_node **stacka, t_list **ops)
{
	t_node	*tmp;
	t_node	*tmpn;

	if (already_sorted(stacka))
		return ;
	tmp = (*stacka)->next;
	if (ft_lstsize_ps(*stacka) == 2)
	{
		if ((*stacka)->content > tmp->content)
			swap(stacka, ops, "sa");
		return ;
	}
	else
	{
		tmpn = tmp->next;
		if ((*stacka)->content > tmp->content)
			case_alpha(stacka, ops, tmp, tmpn);
		else if ((*stacka)->content < tmp->content)
			case_beta(stacka, ops, tmpn);
	}
	return ;
}

void	case_alpha(t_node **stacka, t_list **ops, t_node *tmp, t_node *tmpn)
{
	if (tmp->content < tmpn->content)
	{
		if ((*stacka)->content < tmpn->content)
			swap(stacka, ops, "sa");
		else
			rotate(stacka, ops, "ra");
	}
	else
	{
		swap(stacka, ops, "sa");
		rev_rotate(stacka, ops, "rra");
	}
}

void	case_beta(t_node **stacka, t_list **ops, t_node *tmpn)
{
	if ((*stacka)->content < tmpn->content)
	{
		rev_rotate(stacka, ops, "rra");
		swap(stacka, ops, "sa");
	}
	else
		rev_rotate(stacka, ops, "rra");
}
