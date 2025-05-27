/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:35:31 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/01 08:35:54 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*int main()
{
	t_list *node1, *node2, *head;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));

	node1->content = (int *)1337;
	node2-> content = (int*) 343;

	node1->next = node2;
	node2->next = NULL;

	head = node1;

	printf("size of this list is : %d ",ft_lstsize(head));
	free(node1);
	free(node2);
}*/