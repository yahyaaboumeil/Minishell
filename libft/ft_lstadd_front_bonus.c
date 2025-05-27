/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:21:55 by yaboumei          #+#    #+#             */
/*   Updated: 2024/10/31 20:21:59 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*int main()
{
	t_list *first_nod = malloc(sizeof(t_list));
	int c = 1337;
	first_nod->content = &c;
	first_nod->next = NULL;
	t_list *head = first_nod;
	printf("olde data : %d\n", *(int*)head->content);
	t_list *new_node = malloc(sizeof(t_list));
	c = 1437;
	new_node->content = &c;
	new_node->next = NULL;
	ft_lstadd_front(&head, new_node);
	printf("new data : %d\n", *(int*)head->content);
	free(first_nod);
	free(new_node);

}*/