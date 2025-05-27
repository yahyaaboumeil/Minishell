/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:58:31 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/06 11:28:26 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pnt_d;
	unsigned char	*pnt_c;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	pnt_c = (unsigned char *)src;
	pnt_d = (unsigned char *)dest;
	while (i < n)
	{
		pnt_d[i] = pnt_c[i];
		i++;
	}
	return (dest);
}