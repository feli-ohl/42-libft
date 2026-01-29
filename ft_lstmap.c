/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:06:18 by foehler           #+#    #+#             */
/*   Updated: 2026/01/29 17:56:09 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content_aux;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		content_aux = f(lst->content);
		new_node = ft_lstnew(content_aux);
		if (new_node == NULL)
		{
			del(content_aux);
			ft_lstclear(&new_list, del);
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
