/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:57:48 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/22 14:00:40 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize_ps(t_node *lst)
{
	int		i;
	t_node	*n;

	i = 0;
	if (!lst)
		return (i);
	n = lst;
	while (n)
	{
		i++;
		n = n->next;
	}
	return (i);
}
