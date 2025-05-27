/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:07:08 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/04 11:05:17 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	le_src;

	i = 0;
	le_src = ft_strlen(src);
	if (size == 0)
		return (le_src);
	while (src[i] && (size - 1 > i))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (le_src);
}

/*int main()
{
	char de[6] = "Yahya";
	char const *src = "aboumeil";

	printf("my : %zu\n", ft_strlcpy(de, src,sizeof(de)));
	//printf("them : %d", strlcpy(de, src,sizeof(de)));
}*/