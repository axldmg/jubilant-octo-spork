/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:20:17 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/12 08:46:03 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		count;
	int		start;
	int		end;

	if (needle[0] == '\0')
		return ((char *)haystack);
	count = 0;
	while (haystack[count] && n > 0)
	{
		if (n < ft_strlen(needle))
			return (NULL);
		start = 0;
		end = count;
		while (haystack[end] == needle[start] && haystack[end] && needle[start])
		{
			start++;
			end++;
		}
		if (needle[start] == '\0')
			return ((char *)haystack + count);
		n--;
		count++;
	}
	return (NULL);
}
