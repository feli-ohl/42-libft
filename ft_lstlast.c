/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:03:52 by foehler           #+#    #+#             */
/*   Updated: 2026/01/29 19:50:54 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node of a list.
 * 
 * @param lst The beginning of the list.
 * @return The last node, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	int	size;
	int	i;

	size = ft_lstsize(lst);
	i = 0;
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
