/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:40:09 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/11 22:24:48 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tg_position(t_node **stacka, t_node **stackb)
{
	t_node	*tmpa;
	t_node	*tmpb;

	tmpb = *stackb;
	while (tmpb)
	{
		tmpa = *stacka;
		tmpb->tg_pos = 0;
		while (tmpa && (tmpb->index < tmpa->index))
			tmpa = tmpa->next;
		while (tmpa)
		{
			if (tmpb->index > tmpa->index)
				tmpb->tg_pos = tmpa->position + 1;
			if (tmpb->index < tmpa->index)
				break ;
			tmpa = tmpa->next;
		}
		if (tmpb->tg_pos == ft_lstsize_ps(*stacka))
			tmpb->tg_pos = 0;
		tmpb = tmpb->next;
	}
}

void	costs(t_node **stacka, t_node **stackb)
{
	t_node	*tmpb;

	tmpb = *stackb;
	while (tmpb)
	{
		if (tmpb->position && tmpb->position <= ft_lstsize_ps(*stackb) / 2)
			tmpb->cost_b = tmpb->position;
		else if (tmpb->position && tmpb->position > ft_lstsize_ps(*stackb) / 2)
			tmpb->cost_b = tmpb->position - ft_lstsize_ps(*stackb);
		else
			tmpb->cost_b = 0;
		if (tmpb->tg_pos && tmpb->tg_pos <= ft_lstsize_ps(*stacka) / 2)
			tmpb->cost_a = tmpb->tg_pos;
		else if (tmpb->tg_pos && tmpb->tg_pos > ft_lstsize_ps(*stacka) / 2)
			tmpb->cost_a = tmpb->tg_pos - ft_lstsize_ps(*stacka);
		else
			tmpb->cost_a = 0;
		tmpb = tmpb->next;
	}
}

void	select_node(t_node **stackb, int *grand_cost)
{
	t_node	*tmp;
	int		abs_cost_a;
	int		abs_cost_b;

	tmp = *stackb;
	while (tmp)
	{
		if (tmp->cost_a < 0)
			abs_cost_a = -1 * tmp->cost_a;
		else
			abs_cost_a = tmp->cost_a;
		if (tmp->cost_b < 0)
			abs_cost_b = -1 * tmp->cost_b;
		else
			abs_cost_b = tmp->cost_b;
		tmp->cost = abs_cost_a + abs_cost_b;
		tmp = tmp->next;
	}
	tmp = *stackb;
	while (tmp)
	{
		if (*grand_cost > tmp->cost)
			*grand_cost = tmp->cost;
		tmp = tmp->next;
	}
}
