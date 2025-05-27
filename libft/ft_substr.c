/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:38:17 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/06 08:49:53 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	le;

	if (s == NULL)
		return (NULL);
	le = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (start > le)
		return (ft_strdup(""));
	if ((le - start) < len)
		len = le - start;
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, (s + start), len + 1);
	return (ptr);
}
