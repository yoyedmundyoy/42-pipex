/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:50:17 by etong             #+#    #+#             */
/*   Updated: 2024/06/18 10:58:25 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num(unsigned int nb)
{
	char	str[15];
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (nb)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	while (--i >= 0)
		len += ft_putchar(str[i]);
	return (len);
}

int	ft_putunbr(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	if (!nb)
		len += ft_putchar('0');
	else
		len += print_num(nb);
	return (len);
}
