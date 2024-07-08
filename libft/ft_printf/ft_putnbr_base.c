/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:30:07 by etong             #+#    #+#             */
/*   Updated: 2024/06/18 10:58:16 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_base(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] < ' ' && base[i] > '~'))
			return (0);
		j = 0;
		count = 0;
		while (base[j])
		{
			if (base[j] == base[i] && count > 0)
				return (0);
			else if (base[j] == base[i])
				count++;
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	len;
	char			result[100];

	size = check_base(base);
	len = 0;
	if (size)
	{
		if (!nbr)
			return (ft_putnbr(0));
		i = 0;
		while (nbr)
		{
			result[i] = base[nbr % size];
			nbr /= size;
			i++;
		}
		len = i;
		while (i > 0)
			write(1, &(result[--i]), 1);
	}
	return (len);
}
