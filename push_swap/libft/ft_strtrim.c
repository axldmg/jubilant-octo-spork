/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:25:29 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/13 19:39:52 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_makestr(char const *s1, size_t start, size_t end)
{
	char	*str;
	int		i;

	str = malloc (end - start + 1);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_give_up(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static int	ft_start_position(const char *s1, const char *set)
{
	int	start;
	int	i;

	start = 0;
	i = -1;
	while (set[++i] && s1[start])
	{
		if (set[i] == s1[start])
		{
			i = -1;
			start++;
		}
	}
	return (start);
}

static int	ft_end_position(const char *s1, const char *set)
{
	int	end;
	int	i;

	end = ft_strlen(s1);
	i = -1;
	while (set[++i] && end)
	{
		if (set[i] == s1[end - 1])
		{
			i = -1;
			end--;
		}
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = ft_start_position(s1, set);
	end = ft_end_position(s1, set);
	if (start >= end)
		return (ft_give_up());
	return (ft_makestr(s1, start, end));
}
