/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:52:12 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/04 08:59:49 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (++i < size && *dst)
		dst++;
	if (i == size)
		return (i + ft_strlen(src));
	while (src[++j])
		if (j < size - i - 1)
			*dst++ = src[j];
	*dst = '\0';
	return (i + j);
}
