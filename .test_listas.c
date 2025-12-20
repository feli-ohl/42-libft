/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_listas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:26:37 by foehler           #+#    #+#             */
/*   Updated: 2025/12/20 17:06:26 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// Función 'del' simulada para no crashear con strings 
// Usada para probar ft_lstdelone
void	del_mock(void *content)
{
	printf(" -> (Simulando free) Eliminando contenido: %s\n", (char *)content);
}

// Esta función transforma el contenido a una versión modificada
// (Por ejemplo: Pone la primera letra en 'X')
// Usada para probar ft_lstiter
void	f_modify_mock(void *content)
{
	char *s = (char *)content;
	if (s && s[0] != '\0')
	{
		s[0] = 'X'; // Cambiamos la primera letra por una X
	}
}

// Esta función crea una COPIA y la modifica (ej: 'hola' -> 'Zola')
// Usada para probar ft_lstmap
void	*map_f(void *content)
{
	char *new_str = ft_strdup((char *)content); // Duplicamos para tener memoria nueva
	if (new_str)
		new_str[0] = 'Z'; // Cambiamos la primera letra
	return (new_str);
}
// La función 'del' para limpiar
// Usada para probar ft_lstmap
void	map_del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lista = NULL;

	t_list	*mi_nodo1;
	t_list	*mi_nodo2;
	t_list	*mi_nodo3;

	printf("\n===== TEST FT_LSTNEW =====\n");
	// Vamos a empezar creando el nodo 2 para probar add_front después
	mi_nodo2 = ft_lstnew("Contenido 2");
	if (!mi_nodo2)
		return (1);
	// Lo asignamos como inicio de lista manual
	lista = mi_nodo2;
	printf("Lista actual: %s -> NULL\n", (char *)lista->content);


	printf("\n===== TEST FT_LSTADD_FRONT =====\n");
	mi_nodo1 = ft_lstnew("Contenido 1");
	if (!mi_nodo1)
		return (1);
	// Pasamos la dirección de 'lista'. Ahora el 1 se pondrá antes del 2.
	ft_lstadd_front(&lista, mi_nodo1);
	printf("Primero: %s\n", (char *)lista->content);       // Debe ser Contenido 1
	printf("Segundo: %s\n", (char *)lista->next->content); // Debe ser Contenido 2
		

	printf("\n===== TEST FT_LSTSIZE =====\n");
	printf("Tamaño lista (esperado 2): %d\n", ft_lstsize(lista));


	printf("\n===== TEST FT_LSTLAST =====\n");
	t_list *ultimo = ft_lstlast(lista);
	printf("Contenido del último nodo: %s\n", (char *)ultimo->content);


	printf("\n===== TEST FT_LSTADD_BACK =====\n");
	mi_nodo3 = ft_lstnew("Contenido 3");
	if (!mi_nodo3)
		return (1);
	// Pasamos la dirección de 'lista'. La función recorrerá hasta el final y pegará el 3.
	ft_lstadd_back(&lista, mi_nodo3);
	if (mi_nodo2->next == mi_nodo3) // nodo2 era el último antes, ahora debe apuntar al 3
		printf("El nodo 2 ahora apunta al nodo 3: Correcto\n");
	printf("Nuevo último: %s\n", (char *)mi_nodo3->content);


	printf("\n===== TEST FT_LSTDELONE =====\n");
	// IMPORTANTE: Para borrar el nodo del medio sin romper la lista, 
	// primero apuntamos del 1 al 3.
	printf("Apuntando nodo 1 -> nodo 3...\n");
	mi_nodo1->next = mi_nodo3;
	printf("Borrando nodo 2...\n");
	ft_lstdelone(mi_nodo2, del_mock);
	printf("Estado final de la lista:\n");
	printf("1: %s\n", (char *)lista->content);
	printf("2: %s\n", (char *)lista->next->content); // Ahora el siguiente del 1 es el 3


	printf("\n===== TEST FT_LSTCLEAR =====\n");
	printf("Borrando toda la lista...\n");
	// Pasamos la dirección de 'lista' (&lista)
	ft_lstclear(&lista, del_mock);
	if (lista == NULL)
		printf("¡Éxito! La lista ahora es NULL.\n");
	else
		printf("Error: La lista no es NULL.\n");

		
	printf("\n===== TEST FT_LSTITER =====\n");
	// Usamos arrays para que la memoria sea modificable (writable)
	char	str1[] = "primero";
	char	str2[] = "segundo";
	char	str3[] = "tercero";
	lista = NULL;
	// Creamos la lista: str3 -> str2 -> str1 -> NULL
	ft_lstadd_front(&lista, ft_lstnew(str1));
	ft_lstadd_front(&lista, ft_lstnew(str2));
	ft_lstadd_front(&lista, ft_lstnew(str3));
	printf("--- Antes de iterar ---\n");
	t_list *temp = lista;
	while (temp)
	{
		printf("Nodo: %s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstiter(lista, f_modify_mock);
	printf("--- Después de iterar ---\n");
	temp = lista;
	while (temp)
	{
		printf("Nodo: %s\n", (char *)temp->content);
		temp = temp->next;
	}

	
	printf("\n===== TEST FT_LSTMAP =====\n");
	t_list *lista2 = ft_lstnew(ft_strdup("hola")); // Lista original
	t_list *mapa;
	if (!lista2) 
		return (1);
	// --- TEST ---
	mapa = ft_lstmap(lista2, map_f, map_del);
	// --- VERIFICACIÓN ---
	if (mapa)
	{
		printf("Original: %s (dir: %p)\n", (char *)lista2->content, lista2->content);
		printf("Map     : %s (dir: %p)\n", (char *)mapa->content, mapa->content);
		if (lista2->content != mapa->content)
			printf("ÉXITO: Son listas distintas con contenido nuevo.\n");
	}
	else
		printf("Error: ft_lstmap devolvió NULL.\n");
	// Limpieza
	ft_lstclear(&lista2, map_del);
	ft_lstclear(&mapa, map_del);

	return (0);
}