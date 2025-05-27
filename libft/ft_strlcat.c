/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:32:21 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/07 11:50:52 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	i = 0;
	j = dst_len;
	if (size <= dst_len)
		return (size + src_len);
	while (j < size - 1 && src[i])
		dst[j++] = src[i++];
	dst[j] = 0;
	return (src_len + dst_len);
}
