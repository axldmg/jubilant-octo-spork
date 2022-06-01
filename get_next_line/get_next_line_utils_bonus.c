/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:17:14 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/27 13:31:33 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	if ((char)c == '\0')
		return (tmp + ft_strlen(s, '\0'));
	if (!tmp)
		return (NULL);
	while (*tmp)
	{
		if ((char)c == *tmp)
			return (tmp);
		tmp++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s, char c)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != c)
	{
		len++;
	}
	return (len);
}

void	ft_memcpy(char *dest, char *src, int flag)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (flag)
	{
		while (src[j] != '\n')
			j++;
		j++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2, char c)
{
	int		len_s1;
	int		len_s2;
	char	*str;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1, '\0');
	len_s2 = ft_strlen(s2, c);
	str = malloc(len_s1 + len_s2 + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j] != c)
	{
		str[i] = s2[j];
		i++;
	}
	if (c == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (free(s1), str);
}
