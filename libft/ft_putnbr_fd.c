/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:51:26 by etong             #+#    #+#             */
/*   Updated: 2024/06/07 12:43:39 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the integer ’n’ to the given file
descriptor.
*/

#include "libft.h"

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static void	recurse(int n, int fd, int neg)
{
	if (n == 0)
		return ;
	recurse(n / 10, fd, neg);
	if (neg)
		ft_putchar_fd(-(n % 10) + '0', fd);
	else
		ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	is_neg;

	if (!n)
		ft_putchar_fd('0', fd);
	else
	{
		is_neg = is_negative(n);
		if (is_neg)
			ft_putchar_fd('-', fd);
		recurse(n, fd, is_neg);
	}
}
