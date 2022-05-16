/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:25:45 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/16 20:31:35 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*pointer;
	size_t	check;

	check = nelem * elsize;
	pointer = NULL;
	if (!nelem || !elsize)
	{
		pointer = malloc(0);
		return (pointer);
	}
	if (check / nelem != elsize)
		return (pointer);
	pointer = malloc(nelem * elsize);
	if (pointer)
		ft_bzero(pointer, check);
	return (pointer);
}
