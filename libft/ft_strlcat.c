/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:27:28 by etong             #+#    #+#             */
/*   Updated: 2024/06/07 11:39:23 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total;
	size_t	idx;

	if (!dst && !dstsize)
		return (0);
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		++dst_len;
	while (src[src_len])
		++src_len;
	total = dst_len + src_len;
	if (!dstsize || dst_len >= dstsize)
		return (total);
	idx = 0;
	while (src[idx] && dst_len + idx < dstsize - 1)
	{
		dst[dst_len + idx] = src[idx];
		++idx;
	}
	dst[dst_len + idx] = '\0';
	return (dst_len + src_len);
}
