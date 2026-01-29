/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:09:15 by foehler           #+#    #+#             */
/*   Updated: 2026/01/29 19:50:54 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extracts a substring from a string.
 * 
 * @param s The source string.
 * @param start The starting index.
 * @param len Maximum length of the substring.
 * @return The newly allocated substring, or NULL on failure.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		pointer = malloc(1);
		if (pointer == NULL)
			return (NULL);
		*pointer = '\0';
		return (pointer);
	}
	if (len > s_len - start)
		len = s_len - start;
	pointer = malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	ft_strlcpy(pointer, s + start, len + 1);
	return (pointer);
}
