/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:58:38 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/06 08:44:14 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pnt;
	size_t			i;

	i = 0;
	pnt = (unsigned char *)s;
	while (i < n)
		pnt[i++] = (unsigned char)c;
	return (s);
}
