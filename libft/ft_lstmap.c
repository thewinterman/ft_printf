/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:19:45 by matwinte          #+#    #+#             */
/*   Updated: 2022/11/07 18:14:48 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	node = head;
	if (node == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		node->next = ft_lstnew(f(lst->content));
		node = node->next;
		if (node == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
	}
	return (head);
}
