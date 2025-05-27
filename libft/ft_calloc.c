/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:04:00 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/10 11:56:19 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*b;
	size_t			num_b;

	num_b = nmemb * size;
	i = 0;
	ptr = malloc(nmemb * (size));
	if (ptr == NULL)
		return (NULL);
	b = (unsigned char *)ptr;
	while (num_b > i)
		b[i++] = 0;
	return (ptr);
}
