/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:33:37 by bschoeff          #+#    #+#             */
/*   Updated: 2022/05/19 08:02:07 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(unsigned long n, char *base, int start);
int	ft_putnbr(int n);
int	ft_put_unbr(unsigned int n);
int	ft_puthx(unsigned long n, char *base);

#endif
