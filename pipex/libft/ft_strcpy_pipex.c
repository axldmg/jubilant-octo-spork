/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_pipex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:58:22 by bschoeff          #+#    #+#             */
/*   Updated: 2022/08/26 08:01:21 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char **dst, const char *src)
{
	int	i;

	if (!src)
		return ;
	i = -1;
	dst[0] = malloc(ft_strlen(src) + 1);
	while (src[++i])
		dst[0][i] = src[i];
	dst[0][i] = '\0';
}
