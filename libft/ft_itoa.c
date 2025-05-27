/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:07:58 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/05 17:13:51 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_of_num(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*nor_itoa(char *arr, int n, int len)
{
	int	i;
	int	sum;

	sum = len - 1;
	i = sum;
	if (n < 0)
	{
		arr[0] = '-';
		n = -n;
	}
	while (n)
	{
		arr[i--] = ((n % 10) + '0');
		n /= 10;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = len_of_num(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len] = 0;
	if (n == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	nor_itoa(arr, n, len);
	return (arr);
}
/*int	main(void)
{
		char    *i1 = ft_itoa(-623);
			char    *i2 = ft_itoa(156);
			char    *i3 = ft_itoa(-0);

		printf("%s", i1);
		printf("\n%s", i2);
		printf("\n%s", i3);
}*/
