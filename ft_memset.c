/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:54:14 by foehler-          #+#    #+#             */
/*   Updated: 2026/01/29 17:56:28 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = s;
	i = 0;
	while (i < n)
	{
		*temp = c;
		temp++;
		i++;
	}
	return (s);
}
