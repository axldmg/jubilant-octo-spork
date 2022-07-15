/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:32:28 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/10 11:15:38 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while ((t1 && t1[i]) && (t2 && t2[i]) && t1[i] == t2[i] && i < n)
		i++;
	if (i != n)
		return (t1[i] - t2[i]);
	return (0);
}
