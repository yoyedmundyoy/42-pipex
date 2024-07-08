/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:51 by etong             #+#    #+#             */
/*   Updated: 2024/06/18 10:57:47 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num(int nb)
{
	char	str[15];
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (nb)
	{
		if (nb < 0)
		{
			str[i] = -(nb % 10) + '0';
		}
		else
		{
			str[i] = (nb % 10) + '0';
		}
		nb /= 10;
		i++;
	}
	while (--i >= 0)
	{
		len += ft_putchar(str[i]);
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (!nb)
		len += ft_putchar('0');
	else if (nb < 0)
	{
		len += ft_putchar('-');
		len += print_num(nb);
	}
	else
		len += print_num(nb);
	return (len);
}
