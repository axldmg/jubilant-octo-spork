/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:55:11 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/12 09:13:07 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **lst, t_list **ops, char *word)
{
	t_node	*tmp;
	t_list	*new;

	if (ft_lstsize_ps(*lst) < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (word)
	{
		new = ft_lstnew(word);
		if (!new)
			ft_lstclear(ops, 0);
		else
			ft_lstadd_back(ops, new);
	}
	position(lst);
}

void	push(t_node **dest, t_node **src, t_list **ops, char *word)
{
	t_node	*tmp;
	t_list	*new;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (!(*dest))
		tmp->next = NULL;
	else
		tmp->next = (*dest)->next;
	ft_lstadd_front_ps(dest, tmp);
	if (word)
	{
		new = ft_lstnew(word);
		if (!new)
			ft_lstclear(ops, 0);
		else
			ft_lstadd_back(ops, new);
	}
	position(dest);
	position(src);
}

void	rotate(t_node **lst, t_list **ops, char *word)
{
	t_node	*tmp;
	t_list	*new;

	if (ft_lstsize_ps(*lst) < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(lst, tmp);
	if (word)
	{
		new = ft_lstnew(word);
		if (!new)
			ft_lstclear(ops, 0);
		else
			ft_lstadd_back(ops, new);
	}
	position(lst);
}

void	rev_rotate(t_node **lst, t_list **ops, char *word)
{
	t_node	*tmp;
	t_node	*nil;
	t_list	*new;

	if (ft_lstsize_ps(*lst) < 2)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	nil = *lst;
	while (nil->next != tmp)
		nil = nil->next;
	nil->next = NULL;
	ft_lstadd_front_ps(lst, tmp);
	if (word)
	{
		new = ft_lstnew(word);
		if (!new)
			ft_lstclear(ops, 0);
		else
			ft_lstadd_back(ops, new);
	}
	position(lst);
}
