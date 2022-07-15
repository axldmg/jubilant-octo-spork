/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:21:30 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/09 13:02:39 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	int			i;

	str = s;
	i = 0;
	while (n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
		n--;
	}
	return (NULL);
}
