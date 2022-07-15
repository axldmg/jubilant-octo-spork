/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:39:49 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/11 10:53:23 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew_ps(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->index = 0;
	new->content = nb;
	new->next = NULL;
	new->tg_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->cost = 0;
	return (new);
}
