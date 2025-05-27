/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:08:05 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/01 09:08:26 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

/*int main()
{
	t_list *node1, *node2, *node3, *last_node;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	node1->content = (int *)13;
	node1->next = node2;
	node2->content = (int *)42;
	node2->next = node3;
	node1->content = malloc(sizeof(int));
	*(int *)node1->content = 13;
	node1->next = node2;

	node2->content = malloc(sizeof(int));
	*(int *)node2->content = 42;
	node2->next = node3;

	node3->content = malloc(sizeof(int));
	*(int *)node3->content = 1337;
	node3->next = NULL;

	// Get the last node
	last_node = ft_lstlast(node1);

	// Print the content of the last node
	if (last_node) {
		printf("Last node is: %d\n", *(int *)last_node->content);
	} else {
		printf("The list is empty.\n");
	}

	// Free allocated memory
	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/