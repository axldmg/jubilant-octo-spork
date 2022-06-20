/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:30:18 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/12 08:40:43 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	x;
	char	ch;
	char	*str;

	ch = c;
	str = s;
	x = 0;
	while (x < n)
	{
		*str = ch;
		str++;
		x++;
	}
	return (s);
}
