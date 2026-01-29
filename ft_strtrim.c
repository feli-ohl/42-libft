/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:03:52 by foehler           #+#    #+#             */
/*   Updated: 2026/01/29 19:50:54 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Trims characters from both ends of a string.
 * 
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return The newly allocated trimmed string, or NULL on failure.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	inicio;
	size_t	final;
	char	*trim;

	inicio = 0;
	while (s1[inicio] != '\0' && ft_strchr(set, s1[inicio]) != NULL)
		inicio++;
	final = ft_strlen(s1);
	while (final > inicio && ft_strchr(set, s1[final - 1]) != NULL)
		final--;
	trim = ft_substr(s1, inicio, final - inicio);
	return (trim);
}
