/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:32:02 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/19 08:17:50 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n, char *base, int start)
{
	int	size;

	size = 0;
	if (!n)
		return (ft_putstr("(nil)"));
	if (start)
		size += ft_putstr("0x");
	if (n > 15)
	{
		size += ft_putptr(n / 16, base, 0);
		size += ft_putchar(base[n % 16]);
	}
	else
		size += ft_putchar(base[n]);
	return (size);
}

int	ft_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		size += ft_putchar(n + '0');
	else
	{
		size += ft_putnbr(n / 10);
		size += ft_putchar(n % 10 + '0');
	}
	return (size);
}

int	ft_put_unbr(unsigned int n)
{
	int	size;

	size = 0;
	if (n < 10)
		size += ft_putchar(n + '0');
	else
	{
		size += ft_put_unbr(n / 10);
		size += ft_putchar(n % 10 + '0');
	}
	return (size);
}

int	ft_puthx(unsigned long n, char *base)
{
	int	size;

	size = 0;
	if (n < 16)
		size += ft_putchar(base[n]);
	else
	{
		size += ft_puthx(n / 16, base);
		size += ft_putchar(base[n % 16]);
	}
	return (size);
}
