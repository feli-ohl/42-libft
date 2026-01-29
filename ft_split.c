/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:40:55 by foehler           #+#    #+#             */
/*   Updated: 2026/01/29 19:50:54 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts words in a string separated by a delimiter.
 * 
 * @param s The string to process.
 * @param c The delimiter character.
 * @return The number of words.
 */
static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

/**
 * @brief Frees an array of strings.
 * 
 * @param array The array to free.
 * @param i The number of elements to free.
 */
static void	ft_free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

/**
 * @brief Calculates the length of a word until delimiter.
 * 
 * @param s The string to process.
 * @param c The delimiter character.
 * @return The length of the word.
 */
static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

/**
 * @brief Fills the array with split words.
 * 
 * @param split The array to fill.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return The filled array, or NULL on failure.
 */
static char	**ft_fill_array(char **split, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			len = ft_wordlen(s, c);
			split[i] = ft_substr(s, 0, len);
			if (split[i] == NULL)
			{
				ft_free_array(split, i);
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	split[i] = NULL;
	return (split);
}

/**
 * @brief Splits a string into an array of words.
 * 
 * @param s The string to split.
 * @param c The delimiter character.
 * @return Array of strings, or NULL on failure.
 */
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	if (ft_fill_array(split, s, c) == NULL)
		return (NULL);
	return (split);
}
