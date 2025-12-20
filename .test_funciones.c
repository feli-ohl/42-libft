/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_funciones.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:27:18 by foehler           #+#    #+#             */
/*   Updated: 2025/12/20 13:25:35 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// Función para probar strmapi
// Hay que usar i de alguna forma para que no de un warning...
char    f_strmapi(unsigned int i, char c) { c = i + c - i; return c - 32; }

// Función para probar striteri
void    f_striteri(unsigned int i, char *c) { *c = *c - i + i - 32; }

int	main(void)
{
	printf("===== FUNCIONES DE libc =====\n");
    
    // Test isalpha
    printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));

    // Test isdigit
    printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));

    // Test isalnum
    printf("ft_isalnum('*'): %d\n", ft_isalnum('*'));

    // Test isascii
    printf("ft_isascii(127): %d\n", ft_isascii(127));

    // Test isprint
    printf("ft_isprint(' '): %d\n", ft_isprint(' '));

    // Test strlen
    printf("ft_strlen(\"Hola\"): %zu\n", ft_strlen("Hola"));

    // Test memset
    char buff1[20];
    ft_memset(buff1, 'A', 5);
    buff1[5] = '\0';
    printf("ft_memset (5 'A'): %s\n", buff1);

    // Test bzero
    ft_bzero(buff1, 2);
    // Debemos imprimir caracter a caracter porque hay nulos al principio
    printf("ft_bzero (first 2 bytes): %d %d %c\n", buff1[0], buff1[1], buff1[2]);

    // Test memcpy
    char src[] = "CopyMe";
    char dest[20];
    ft_memcpy(dest, src, 7);
    printf("ft_memcpy: %s\n", dest);

    // Test memmove (overlap)
    char move_str[] = "123456789";
    ft_memmove(move_str + 2, move_str, 3); // Copia "123" en la pos de "345"
    printf("ft_memmove (overlap src < dst): %s (esperado: 121236789)\n", move_str);

    // Test strlcpy
    char lcpy_dst[20];
    size_t r1 = ft_strlcpy(lcpy_dst, "Largestring", 5);
    printf("ft_strlcpy (size 5): %s, ret: %zu\n", lcpy_dst, r1);

    // Test strlcat
    char lcat_dst[20] = "Hello";
    size_t r2 = ft_strlcat(lcat_dst, " World", 20);
    printf("ft_strlcat: %s, ret: %zu\n", lcat_dst, r2);

    // Test toupper
    printf("ft_toupper('a'): %c\n", ft_toupper('a'));

    // Test tolower
    printf("ft_tolower('Z'): %c\n", ft_tolower('Z'));

    // Test strchr
    const char *s = "Hola Mundo";
    printf("ft_strchr(s, 'M'): %s\n", ft_strchr(s, 'M'));

    // Test strrchr
    printf("ft_strrchr(s, 'o'): %s\n", ft_strrchr(s, 'o'));

    // Test strncmp
    printf("ft_strncmp(\"test\", \"best\", 4): %d\n", ft_strncmp("test", "best", 4));

    // Test memchr
    printf("ft_memchr(\"ABCDE\", 'C', 5): %s\n", (char *)ft_memchr("ABCDE", 'C', 5));

    // Test memcmp
    printf("ft_memcmp(\"ABC\", \"ABD\", 3): %d\n", ft_memcmp("ABC", "ABD", 3));

    // Test strnstr
    printf("ft_strnstr(\"Foo Bar Baz\", \"Bar\", 11): %s\n", ft_strnstr("Foo Bar Baz", "Bar", 11));
    
    // Test atoi
    printf("ft_atoi(\"   -42\"): %d\n", ft_atoi("   -42"));

    // Test calloc
    int *int_array;
    int_array = (int *)ft_calloc(5, sizeof(int));
    if (int_array)
    {
        printf("ft_calloc (int array): %d %d (deben ser 0)\n", int_array[0], int_array[4]);
        free(int_array);
    }
    else
        printf("ft_calloc fallo\n");

    // Test strdup
    char *dup_str;
    dup_str = ft_strdup("Duplicame");
    if (dup_str)
    {
        printf("ft_strdup: %s\n", dup_str);
        free(dup_str);
    }
    else
        printf("ft_strdup fallo\n");

    printf("\n===== FUNCIONES ADICIONALES =====\n");

    // Test substr
    char *substring;
    substring = ft_substr(s, 5, 3);
    if (substring)
    {
        printf("ft_substr(s, 5, 3): %s\n", substring);
        free(substring);
    }
    else
        printf("ft_substr fallo\n");

    // Test strjoin
    char *join;
    join = ft_strjoin("Hola", " Mundo");
    if (join)
    {
        printf("ft_strjoin(\"Hola\", \" Mundo\"): %s\n", join);
        free(join);
    }
    else
        printf("ft_strjoin fallo\n");

    // Test strtrim
    char set[] = "-. ";
    const char *s1 = "..- Hola Mundo .";
    char *trim = ft_strtrim(s1, set);
    if (trim)
    {
        printf("ft_strtrim(s1, set): %s\n", trim);
        free(trim);
    }
    else
        printf("ft_strtrim fallo\n");

    // Test split
    char **split_res = ft_split("  Hola   mundo  42 ", ' ');
    int i = 0;
    if (split_res)
    {
        printf("ft_split(\"  Hola   mundo  42 \", ' '): [");
        while (split_res[i] != NULL)
        {
            printf("|%s|", split_res[i]);
            free(split_res[i++]); // Imprimimos y liberamos al vuelo
        }
        free(split_res);
        printf("]\n");
    }
    else
        printf("ft_split fallo\n");

    // Test itoa
    int n = 0;
    char *itoa = ft_itoa(n);
    if (itoa)
    {
        printf("ft_itoa(0): %s\n", itoa);
        free(itoa);
    }
    else
        printf("ft_itoa fallo\n");

    // Test strmapi
    char *res = ft_strmapi("abc", f_strmapi);
    if (res)
    {
        printf("ft_strmapi(\"abc\", f_strmapi): %s\n", res);
        free(res);
    }
    else
        printf("ft_strmapi fallo\n");

    // Test striteri
    char str[] = "abc";
    ft_striteri(str, f_striteri);
    printf("ft_striteri(\"abc\", f_striteri): %s\n", str);

    // Test putchar_fd
    printf("ft_putchar_fd('a', 1): ");
    ft_putchar_fd('a', 1);
    printf("\n");

    // Test putstr_fd
    printf("ft_putstr_fd(str, 1): ");
    ft_putstr_fd(str, 1);
    printf("\n");

    // Test putendl_fd
    printf("ft_putendl_fd(str, 1): ");
    ft_putendl_fd(str, 1);
    printf("\n");

    // Test putnbr_fd
    printf("ft_putnbr_fd(-42, 1): ");
    ft_putnbr_fd(-42, 1);
    printf("\n");

    return (0);
}
