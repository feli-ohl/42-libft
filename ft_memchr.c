/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:27:05 by foehler-          #+#    #+#             */
/*   Updated: 2026/01/29 19:50:54 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Scans memory for a character.
 * 
 * @param s Pointer to the memory area.
 * @param c Character to search for.
 * @param n Number of bytes to scan.
 * @return Pointer to the matching byte, or NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		temp++;
		n--;
	}
	return (NULL);
}
