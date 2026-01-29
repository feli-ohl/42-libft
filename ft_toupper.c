/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:20:12 by foehler-          #+#    #+#             */
/*   Updated: 2026/01/29 19:50:52 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lowercase letter to uppercase.
 * 
 * @param c The character to convert.
 * @return The uppercase equivalent if applicable, otherwise c unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
