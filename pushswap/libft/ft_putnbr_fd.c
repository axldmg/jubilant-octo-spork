/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:50:31 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/12 08:41:07 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		c = '-';
		write(fd, &c, 1);
		nb *= -1;
	}
	if (nb / 10 == 0)
	{
		c = nb + '0';
		write(fd, &c, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		c = nb % 10 + '0';
		write(fd, &c, 1);
	}
}
