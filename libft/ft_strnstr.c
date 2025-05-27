/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:45:21 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/06 11:35:47 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_find(const char *big, const char *little, size_t pos,
		size_t len)
{
	size_t	i;

	i = 0;
	while (big[pos] && little[i] && len > pos)
	{
		if (big[pos] != little[i])
			return (i);
		pos++;
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			if (ft_strlen(little) == is_find(big, little, i, len))
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
