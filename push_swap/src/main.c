/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:20:58 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/12 10:17:41 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_node	*stacka;
	t_node	*stackb;
	t_list	*ops;

	stacka = NULL;
	stackb = NULL;
	ops = NULL;
	if (ac == 1)
		return (0);
	i = 0;
	while (av[++i])
	{
		if (!populate(&stacka, av[i]))
			return (ft_putstr_fd("Error\n", 2), release(&stacka), 2);
	}
	if (!compliance_duplicates(&stacka))
		return (ft_putstr_fd("Error\n", 2), release(&stacka), 2);
	if (already_sorted(&stacka))
		return (release(&stacka), 0);
	sort(&stacka, &stackb, &ops);
	about_ops(&ops);
	return (release(&stackb), release(&stacka), 0);
}

int	populate(t_node **stacka, char *str)
{
	long	x;
	t_node	*new;

	if (!compliance_arguments(str))
		return (0);
	x = ft_atoi(str);
	new = ft_lstnew_ps(x);
	if (!new)
		return (0);
	ft_lstadd_back_ps(stacka, new);
	return (1);
}

void	about_ops(t_list **ops)
{
	if (*ops)
	{
		sanitize(ops);
		display(ops);
		ft_lstclear(ops, 0);
	}
}
