/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:28:33 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/19 10:18:21 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long), "0123456789abcdef", 1));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_put_unbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthx(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthx(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else
		return (ft_putchar(c));
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			i;
	int			clicker;

	i = 0;
	clicker = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (ft_strchr("cspdiuxX", fmt[++i]))
			{
				clicker += ft_format(args, fmt[i++]);
				continue ;
			}
		}
		clicker += ft_putchar(fmt[i++]);
	}
	va_end(args);
	return (clicker);
}
