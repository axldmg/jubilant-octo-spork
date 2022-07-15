/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:02:06 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/12 11:04:31 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str1;
	const char	*str2;
	int			i;

	str1 = dest;
	str2 = src;
	i = 0;
	while (n)
	{
		str1[i] = str2[i];
		i++;
		n--;
	}
	return (str1);
}
