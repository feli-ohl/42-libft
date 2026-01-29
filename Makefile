NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
      ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
      ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "LIBRERÍA $(NAME) CREADA"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Archivos objeto eliminados"

fclean: clean
	@rm -rf $(NAME)
	@rm -f test_funciones.c test_listas.c runner_func runner_list
	@echo "LIBRERÍA $(NAME) ELIMINADA"

re: fclean all

URL_FUNC = https://raw.githubusercontent.com/feli-ohl/Libft/refs/heads/main/TESTS/test_funciones.c
URL_LIST = https://raw.githubusercontent.com/feli-ohl/Libft/refs/heads/main/TESTS/test_listas.c

test: all
	@echo "Descargando tests desde GitHub..."
	@curl -s -O $(URL_FUNC)
	@curl -s -O $(URL_LIST)
	@echo "Compilando..."
	@$(CC) $(CFLAGS) test_funciones.c -L. -lft -o runner_func
	@$(CC) $(CFLAGS) test_listas.c -L. -lft -o runner_list
	@echo "Archivos ejecutables runner_func y runner_list creados correctamente."
	@echo "Para borrar los archivos de tests y los ejecutables, ejecutar 'make fclean'."

.PHONY: all clean fclean re test
