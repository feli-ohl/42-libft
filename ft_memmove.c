/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler- <foehler-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:31:08 by foehler-          #+#    #+#             */
/*   Updated: 2025/12/19 13:48:40 by foehler-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;
	if (temp_dest < temp_src)
	{
		while (n--)
			*temp_dest++ = *temp_src++;
	}
	else
	{
		while (n > 0)
		{
			temp_dest[n - 1] = temp_src[n - 1];
			n--;
		}
	}
	return (dest);
}
