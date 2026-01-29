/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:23:48 by foehler           #+#    #+#             */
/*   Updated: 2026/01/29 19:50:54 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of digits in an integer.
 * 
 * @param n The integer to count.
 * @return The number of digits including sign.
 */
static size_t	ft_count_digits(int n)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

/**
 * @brief Converts an integer to a string.
 * 
 * @param n The integer to convert.
 * @return The newly allocated string representation, or NULL on failure.
 */
char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	num;

	num = n;
	len = ft_count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
