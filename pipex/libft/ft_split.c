/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:43:11 by bschoeff          #+#    #+#             */
/*   Updated: 2022/08/22 14:26:57 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char	**tab, int index)
{
	index++;
	while (--index)
	{
		free(tab[index]);
	}
	return (tab);
}

static int	ft_word_len(const char *s, char c, int i)
{
	int	nb;

	nb = 0;
	while (s[i] && s[i++] != c)
		nb++;
	return (nb);
}

static int	ft_word_count(const char *s, char c)
{
	int	nb;
	int	i;

	if (!s || !*s)
		return (0);
	nb = 0;
	i = -1;
	while (s[++i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c)
			{
				if (!s[i + 1])
					break ;
				i++;
			}
		}
	}
	return (nb);
}

static char	**ft_populate(char **tab, const char *s, char c)
{
	int	i;
	int	index;
	int	j;

	index = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			tab[index] = malloc(ft_word_len(s, c, i) + 1);
			if (!tab)
				return (ft_free(tab, index));
			while (s[i] != c && s[i])
				tab[index][j++] = s[i++];
			tab[index][j] = '\0';
			if (!s[i])
				break ;
			i--;
			index++;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**tab;

	words = ft_word_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	if (words == 0)
		return (tab);
	return (ft_populate(tab, s, c));
}
