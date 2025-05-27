/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:31:07 by yaboumei          #+#    #+#             */
/*   Updated: 2025/01/19 11:40:02 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*pnt_s;
	unsigned char		*pnt_d;
	int					i;

	pnt_d = (unsigned char *)dest;
	pnt_s = (unsigned char *)src;
	if (n == 0 || pnt_s == pnt_d)
		return (dest);
	if (pnt_d > pnt_s)
	{
		i = n;
		while (i--)
			pnt_d[i] = pnt_s[i];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

