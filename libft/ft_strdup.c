/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:47:48 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/12 08:43:36 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (dup);
	i = -1;
	while (s[++i])
	{
		dup[i] = s[i];
	}
	dup[i] = '\0';
	return (dup);
}
