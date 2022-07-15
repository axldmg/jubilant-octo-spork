/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:41:57 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/12 08:49:59 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_stack(t_node **stacka, t_node **stackb, t_list **ops)
{
	int		max;

	max = ft_lstsize_ps(*stacka) - 1;
	while (ft_lstsize_ps(*stacka) > 3)
	{
		if ((*stacka)->index == 0 || (*stacka)->index == max)
			rotate(stacka, ops, "ra");
		else
			push(stackb, stacka, ops, "pb");
	}
	three_stack(stacka, ops);
	while (*stackb)
	{
		tg_position(stacka, stackb);
		costs(stacka, stackb);
		proceed(stacka, stackb, ops);
	}
	finalize(stacka, ops);
}

void	proceed(t_node **stacka, t_node **stackb, t_list **ops)
{
	t_node	*tmp;
	int		grand_cost;

	grand_cost = ft_lstsize_ps(*stacka) + ft_lstsize_ps(*stackb);
	select_node(stackb, &grand_cost);
	tmp = *stackb;
	while (tmp)
	{
		if (tmp->cost == grand_cost)
		{
			execute_b(stackb, tmp, ops);
			execute_a(stacka, tmp, ops);
			push(stacka, stackb, ops, "pa");
			break ;
		}
		tmp = tmp->next;
	}
}

void	execute_b(t_node **stackb, t_node *tmp, t_list **ops)
{
	while (tmp->cost_b)
	{
		if (tmp->cost_b > 0)
		{
			rotate(stackb, ops, "rb");
			tmp->cost_b--;
		}
		else if (tmp->cost_b < 0)
		{
			rev_rotate(stackb, ops, "rrb");
			tmp->cost_b++;
		}
	}
}

void	execute_a(t_node **stacka, t_node *tmp, t_list **ops)
{
	while (tmp->cost_a)
	{
		if (tmp->cost_a > 0)
		{
			rotate(stacka, ops, "ra");
			tmp->cost_a--;
		}
		else if (tmp->cost_a < 0)
		{
			rev_rotate(stacka, ops, "rra");
			tmp->cost_a++;
		}
	}
}

void	finalize(t_node **stacka, t_list **ops)
{
	t_node	*tmp;
	int		cost;

	tmp = *stacka;
	cost = 0;
	while (tmp->index)
	{
		cost++;
		tmp = tmp->next;
	}
	if (cost > ft_lstsize_ps(*stacka) / 2)
		cost = cost - ft_lstsize_ps(*stacka);
	while (cost)
	{
		if (cost > 0)
		{
			rotate(stacka, ops, "ra");
			cost--;
		}
		if (cost < 0)
		{
			rev_rotate(stacka, ops, "rra");
			cost++;
		}
	}
}
