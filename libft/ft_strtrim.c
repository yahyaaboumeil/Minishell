/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:07:41 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/10 09:14:14 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		le;
	int		j;
	int		i;
	int		buf_i;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	le = trim(s1, set) + 1;
	if (le <= 0)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (le + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	j = i;
	buf_i = 0;
	while (le + j > i)
	{
		ptr[buf_i++] = s1[i++];
	}
	ptr[buf_i] = '\0';
	return (ptr);
}
