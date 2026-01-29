/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:51:19 by foehler           #+#    #+#             */
/*   Updated: 2026/01/29 19:50:54 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory and initializes it to zero.
 * 
 * @param count Number of elements to allocate.
 * @param size Size of each element.
 * @return Pointer to the allocated memory, or NULL on failure.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	total_size;

	total_size = count * size;
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, total_size);
	return (pointer);
}
