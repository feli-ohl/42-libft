/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler- <foehler-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:12:46 by foehler-          #+#    #+#             */
/*   Updated: 2025/11/21 15:48:12 by foehler-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	printf("ft_isalpha(%c) = %d\n", '7', ft_isalpha('7'));
	printf("ft_isalpha(%c) = %d\n", 'A', ft_isalpha('A'));
	printf("\n");
	printf("ft_isdigit(%c) = %d\n", '7', ft_isdigit('7'));
	printf("ft_isdigit(%c) = %d\n", 'A', ft_isdigit('A'));
	printf("\n");
	printf("ft_isalnum(%c) = %d\n", '7', ft_isdigit('7'));
	printf("ft_isalnum(%c) = %d\n", 'A', ft_isdigit('A'));
	printf("\n");
	printf("ft_isascii(%c) = %d\n", '7', ft_isascii('7'));
	printf("ft_isascii(128) = %d\n", ft_isdigit(128));
	printf("\n");
	printf("ft_isalnum(%c) = %d\n", '7', ft_isdigit('7'));
	printf("ft_isalnum(%c) = %d\n", 'A', ft_isdigit('A'));
	return (0);
}
