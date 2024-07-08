/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:55:24 by etong             #+#    #+#             */
/*   Updated: 2024/06/18 11:22:48 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(void *ptr, char *base)
{
	unsigned long	size;
	unsigned long	i;
	unsigned int	len;
	unsigned long	nbr;
	char			result[100];

	size = 16;
	len = 0;
	if (!ptr)
		return (ft_putstr("0x") + ft_putchar('0'));
	nbr = (unsigned long) ptr;
	if (size)
	{
		i = 0;
		while (nbr)
		{
			result[i] = base[nbr % size];
			nbr /= size;
			++i;
		}
		len += ft_putstr("0x") + i;
		while (i > 0)
			write(1, &(result[--i]), 1);
	}
	return (len);
}
