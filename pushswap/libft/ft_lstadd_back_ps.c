/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_ps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:04:08 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/22 13:44:53 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_ps(t_node **lst, t_node *new)
{
	t_node	*n;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	n = *lst;
	while (n->next)
		n = n->next;
	n->next = new;
}
