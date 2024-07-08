/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:56:01 by etong             #+#    #+#             */
/*   Updated: 2024/06/06 14:25:52 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

#include "libft.h"

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	get_size(int n)
{
	int	i;

	i = 0;
	i += is_negative(n);
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static int	itoa_result(char *result, int n, int neg)
{
	int	i;

	if (n == 0)
	{
		if (neg)
			return (1);
		return (0);
	}
	i = itoa_result(result, n / 10, neg);
	if (neg)
		result[i] = -(n % 10) + '0';
	else
		result[i] = (n % 10) + '0';
	return (i + 1);
}

char	*handle_zero(void)
{
	char	*result;

	result = malloc(sizeof(char) * 2);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		neg;
	int		size;

	if (!n)
		return (handle_zero());
	size = get_size(n);
	neg = is_negative(n);
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	if (neg)
		result[0] = '-';
	itoa_result(result, n, neg);
	result[size] = '\0';
	return (result);
}
