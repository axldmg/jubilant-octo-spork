/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:54:08 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/11 13:54:26 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstlast_ps(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!tmp || !lst)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
