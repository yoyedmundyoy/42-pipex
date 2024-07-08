/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:42:45 by etong             #+#    #+#             */
/*   Updated: 2024/06/07 12:33:21 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	char	*ptr;
	int		num;

	sign = 1;
	ptr = (char *)str;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		++ptr;
	if (*ptr == '-' || *ptr == '+')
	{
		if (!ft_isdigit(*(ptr + 1)))
			return (0);
		else if (*ptr == '-')
			sign *= -1;
		++ptr;
	}
	num = 0;
	while (ft_isdigit(*ptr))
	{
		num = (num * 10) + (*ptr - '0');
		ptr++;
	}
	return (sign * num);
}

// int	ft_atoi(const char *str)
// {
// 	int		sign;
// 	char	*ptr;
// 	int		num;

// 	sign = 1;
// 	num = 0;
// 	ptr = (char *)str;
// 	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
// 		ptr++;
// 	if (*ptr == '-')
// 	{
// 		if (!ft_isdigit(*(ptr + 1)))
// 			return (0);
// 		sign *= -1;
// 	}
// 	while (ft_isdigit(*ptr))
// 	{
// 		num = (num * 10) + (*ptr - '0');
// 		++ptr;
// 	}
// 	return (sign * num);
// }
