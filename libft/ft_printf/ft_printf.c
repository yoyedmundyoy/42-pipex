/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:52:45 by etong             #+#    #+#             */
/*   Updated: 2024/06/18 11:31:50 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char *format, va_list args, int i)
{
	char	*hexbase_low;

	hexbase_low = "0123456789abcdef";
	if (format[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i] == 'p')
		return (ft_printhex(va_arg(args, void *), hexbase_low));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[i] == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format[i] == 'x')
		return (ft_putnbr_base((unsigned int) va_arg(args, int), hexbase_low));
	else if (format[i] == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format[i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			len += handle_format(format, args, i);
		}
		else
			len += ft_putchar(format[i]);
		++i;
	}
	va_end(args);
	return (len);
}
