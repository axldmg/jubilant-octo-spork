/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:25:45 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/13 12:13:43 by bschoeff         ###   ########.fr       */
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
	ft_bzero(pointer, check);
	return (pointer);
}
/*
int	main(void)
{
	printf("%p\n", calloc(SIZE_MAX, 2147483647));
	printf("%p\n", ft_calloc(SIZE_MAX, 2147483647));
}*/
