/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:06:57 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/13 19:38:14 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_n(long n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_makechar(char *nb, long n)
{
	int	i;

	i = ft_len_n((long)n);
	if (n < 0)
	{
		nb[0] = '-';
		n *= -1;
	}
	nb[i] = '\0';
	if (n == 0)
		nb[0] = '0';
	while (n)
	{
		i--;
		nb[i] = (n % 10) + '0';
		n /= 10;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*nb;

	nb = malloc(ft_len_n((long)n) + 1);
	if (!nb)
		return (NULL);
	return (ft_makechar(nb, (long)n));
}
