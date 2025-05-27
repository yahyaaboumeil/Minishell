/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:29:07 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/06 11:37:51 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			s = ptr;
		ptr++;
	}
	if (c == '\0')
	{
		s = ptr;
		return ((char *)s);
	}
	else if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
