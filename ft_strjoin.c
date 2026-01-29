/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:46:30 by foehler           #+#    #+#             */
/*   Updated: 2026/01/29 19:50:54 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates two strings into a new string.
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The newly allocated concatenated string, or NULL on failure.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	pointer = malloc(s1_len + s2_len + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	while (s2[i - s1_len] != '\0')
	{
		pointer[i] = s2[i - s1_len];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
