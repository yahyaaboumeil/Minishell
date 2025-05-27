/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:25:37 by yaboumei          #+#    #+#             */
/*   Updated: 2024/11/02 09:54:45 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = new;
			new->next = NULL;
			return ;
		}
		temp = temp->next;
	}
}
/*int main() {
	t_list *node1, *node2, *node3, *head;
	int c = 1337;

	// Initialize node1
	node1 = malloc(sizeof(t_list));
	node1->content = &c;
	node1->next = NULL; // Initialize next to NULL

	// Initialize node2
	node2 = malloc(sizeof(t_list));
	int f = 13;
	node2->content = &f;
	node2->next = NULL;

	// Set up the list
	node1->next = node2; // Now node1 points to node2
	head = node1;

	// Get the last node before adding
	t_list *lastNodeBefore = ft_lstlast(head);
	printf("Last node before add: %d\n", *(int *)lastNodeBefore->content);

	// Initialize node3
	int newContent = 1; // Using a separate variable for new content
	node3 = malloc(sizeof(t_list));
	//node2->next = node3;
	node3->content = &newContent; // Assign new content
	node3->next = NULL; // Set next to NULL
	head = node1;

 printf("%s " , "yahay");
	// Add node3 to the end of the list
	ft_lstadd_back(&head, node3);

	// Get the last node after adding
	head = node1;
 t_list *lastNodeAfter = ft_lstlast(head);
	printf("Last node after add: %d\n", *(int *)lastNodeAfter->content);

	// Free the allocated memory (not shown here for simplicity)
	// You should free each node to avoid memory leaks.

	return (0);
}*/
/*int main()
{
	t_list *node1, *new, *head;
	node1 = NULL;
	new = malloc(sizeof(t_list));
	new->next = NULL;
	int f = 33;
	new->content = &f;

		ft_lstadd_back(&node1, new);
		head = node1;
 t_list *lastNodeAfter = ft_lstlast(head);
	printf("Last node : %d\n", *(int *)lastNodeAfter->content);
}*/
